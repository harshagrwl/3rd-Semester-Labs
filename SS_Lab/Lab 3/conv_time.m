N=-5:5;
u=[zeros(1,5),ones(1,6)];
g=zeros(size(N));
g(N>=1)=1;
h=exp(-N).*u;
N1=length(g);
N2=length(h);
M = N1+N2-1;
y = conv(g,h);
subplot(1,1,1);
n3=0:M-1;
stem(n3,y);
ylabel('Amplitude->');
xlabel('N->');
disp('Linear Convolution:');y
