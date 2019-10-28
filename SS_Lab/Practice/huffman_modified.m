clear all; clc;
% Getting charecter probabilities from file
[filename,datapath] = uigetfile('*.*', 'select the file');
if isequal(filename,0)
disp('User selected Cancel');
else
disp(['User selected ', fullfile(datapath,filename)]);
end
fid = fopen(filename);
ftell(fid)
tline1 = fgetl(fid) % read the first line
% str = string(tline1)
sym_dict=unique(tline1);
In_s = sym_dict; %Input symbols
% Calculate probabilities of the symbols
for k1=1:length(sym_dict)
prob(k1) = (sum(tline1==sym_dict(k1)))/length(tline1);
end
[z i]=sort(prob,'ascend');
sort_u =sym_dict(i);
In_p = z;
org_len = length(In_p);
%We have sorted array of probabilities in ascending order with track of symbols
ind=1;
len_tr = [org_len];
pos_tr = [0];
total_array(ind,:)=In_p;
append1=[];
lp_j=1;
while(ind<org_len-1)
firstsum = In_p(lp_j)+In_p(lp_j+1); %sum the lowest probabilities
append1 = [append1,firstsum]; %appending sum in array
In_p = [In_p((lp_j+2):length(In_p)),firstsum]; % reconstrucing prob array
In_p = sort(In_p);
ind = ind+1;
total_array(ind,:) = [In_p,zeros(1,org_len-length(In_p))]; %setting track of probabilities
len_tr = [len_tr,length(In_p)]; %lengths track
for i=1:length(In_p)
if(In_p(i)==firstsum)
pos = i; %position after swapping of new sum
end
end
pos_tr = [pos, pos_tr];
end
main_arr = total_array';
%columns indicates no.of times we have done sorting which length-1;
%rows have the prob values with zero padded at the end.
code = cell(org_len,org_len-1); % create cell array
col=org_len-1;
row=1;
% Assigning 0 and 1 to 1st and 2nd row of last column
code{row,col}='0';
code{row+1,col}='1';
while col~=1
i=1;
x=1;
z=0;
if (main_arr(row,col-1) + main_arr(row+1,col-1))==main_arr(row,col)
code{row,col-1}=[code{row,col} '0'];
code{row+1,col-1}=[code{row,col} '1'];
while ~isempty(code{row+i,col})
code{row+1+i,col-1}=code{row+i,col};
i=i+1;
end
else
code{row,col-1}=[code{row+1,col} '0'];
code{row+1,col-1}=[code{row+1,col} '1'];
while ~isempty(code{row+x,col})
code{row+1+x,col-1}=code{row+z,col};
x=x+1;
z=z+2;
end
end
col=col-1;
end