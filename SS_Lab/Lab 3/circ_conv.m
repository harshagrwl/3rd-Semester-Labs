clc;
g = [1, -1, -1, -1, 1, 0, 1, 2];
h = [5, -4, 3, 2, -1, 1, 0, -1];
N1=length(g);
N2=length(h);
N=max(N1,N2);
N3=N1-N2;

if(N3>0)
    h=[h,zeros(1,N3)];
else
    g=[g,zeros(1,-N3)];
end
for n=1:N;
    y(n)=0;
    for i=1:N;
        j=n-i+1;
        if(j<=0)
            j = N+j;
        end
        y(n)=[y(n)+(g(i)*h(j))];
    end
end
disp('Circular Convolution: ');y
subplot(2,1,1);
stem(y);
xlabel('N->');
ylabel('Amplititude->');