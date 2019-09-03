N=-5:5;
u=[zeros(1,5),ones(1,6)];
g=zeros(size(N));
g(N>=-2)=1;
g1(N>=2)=1;
h=(1/2).^(N-2).*g1;
N1=length(g);
N2=length(h);
H = [h,zeros(1,N2-1)];
G = [g,zeros(1,N1-1)];
M = N1+N2-1;
for i=1:M
    A(i) = 0;
    for j = 1:N1
        if(i-j+1 > 0)
            A(i) = A(i)+H(j)*G(i-j+1)
        else
        end
    end
end
subplot(1,1,1);
n3=0:M-1;
stem(n3,A);
ylabel('Amplitude->');
xlabel('N->');
