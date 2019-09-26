function [Y] = branchandnodefft(y,typef)
N = length(y);                               
%% define tree structure
bl = factor(N);                              
if length(bl) == 1
    disp('No optimized tree structure exists for prime N... ')
    disp('Sorry, for large N, this may take minutes!');
    Y = DFT(y,N,typef);
else
bl = bl(1:end-1);                            %decimate until Ml is prime
nl = zeros(1,length(bl));                    %node per level preallocation
Ml = zeros(1,length(bl));                    %elements ber branch
nl(1) = 1; bl = cat(2,1,bl); Ml(1) = N;      %declare level 0
for l = 1:length(bl)-1                       %for each tree level
    nl(l+1) = bl(l) * nl(l);                 %find nodes per level
    Ml(l+1) = Ml(l) / bl(l+1);               %find elements per branch @l
end
El = bl.*Ml;                                 %elements per node 
L = l;                                       %define active levels

INDEX = zeros(length(Ml)-1,N);               %preallocate reindexing levels
INDEX = cat(1,y,INDEX);                      %load in lvl 0
for l = 1:L                                  %for active tree levels
    n=1; k=1;                                %reset n,k for new level
    for ni = 1:nl(l+1)                       %for each node per level
        for bi = 1:bl(l+1)                   %for each branch per node
            INDEX(l+1,n:n+Ml(l+1)-1) = ...      %decimate branch
                INDEX(l,k:bl(l+1):El(l+1)+k-1);
            n = n + Ml(l+1);                 %hop to next solution location
            k = k+1;                         %iterate to adjacent branch
        end
            k=ni*El(l+1)+1;                  %hop to next node in level
    end
end
%% compute FFT
bl = flip(bl); nl = flip(nl); Ml = flip(Ml); %flip tree instructions 
El = flip(El);
BUTTER = zeros(length(Ml),N);                %preallocate FFT upsample tree
for l = 1:L+1                                %for all active levels
    n = 1; k =1;                             %reset n,k for new level
    if l == 1                                %First level is the DFT level
    for ni = 1:nl(l)                         %for each node per level
        for bi = 1:bl(l)                     %for each branch per node
            Fy = DFT(INDEX(end,n:n+Ml(1)-1),Ml(1),typef); %take DFT
            BUTTER(1,n:n+Ml(1)-1) = Fy;      %load to main array
            n = n + Ml(1);                   %hop to next solution location
        end
    end
    else                                     %Upsample through lvls > 1
    for ni = 1:nl(l-1)                       %for each node per level
        if bl(l-1) == 2                      %if bl == 2 use conj twiddle
            CONJ = ...                       %twiddle odd level
                BUTTER(l-1,n+Ml(l-1):n+2*Ml(l-1)-1) .* ...
                1i.^(typef*2*(0:1/Ml(l-1):1-1/Ml(l-1)));
            BUTTER(l,n:n+El(l-1)-1) = ...    %conj with even lvl
                [BUTTER(l-1,n:n+Ml(l-1)-1) + CONJ ,...
                BUTTER(l-1,n:n+Ml(l-1)-1) - CONJ];
        elseif bl(l-1) > 2                   %else use non-conj twiddle
            for bi = 1:bl(l-1)               %for each branch in node
            tempcomp = ...                   %send to non-conj twiddle fct
            NONCONJfct(BUTTER(l-1,k:k+Ml(l-1)-1),bi,Ml(l-1),bl(l-1),typef);
            BUTTER(l,n:n+El(l-1)-1) = tempcomp + ...
                BUTTER(l,n:n+El(l-1)-1);     %superimpose to main array
            k = k + Ml(l-1);                 %iterate computation location
            end
         end
            n = ni*El(l-1)+1;                %hop to next node in level
            k = n;                           %computations as well
    end
    end
end
Y = BUTTER(end,:);                           %extract FD spectrum
end
end
%% function calls
function [Fy] = DFT(y,N,typef)               %DFT main function                                 
Fy=zeros(1,N);                               %preallocate Fy                   
for Fit=1:1:N                                %test ALL combinations
    Fy(Fit)=sum(y.*1i.^(typef*4*(Fit-1)*(0:1/N:1-1/N))); 
end  
end
function [Fyp] = NONCONJfct(Y,bi,Ml,b,typef) %Non-conjugating twiddle fct
N = Ml*b;                                    %upsample size
FY = Y;                                      %hold local FD
for p = 1:b-1                                %periodically extend FD
FY = cat(2,Y,FY);
end
if bi == 1                                   %branch 1 has no twiddle
Fyp = FY;                    
else                                         %twiddle remaining branches
Fyp = FY.*1i.^(4*typef*(bi-1)*(0:1/N:1-1/N));
end
end