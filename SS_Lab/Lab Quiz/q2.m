x = [0 2 1 0];
h = [3 2 1];
m = length(x);
n = length(h);
X = [x,zeros(1,n-1)];
H = [h,zeros(1,m-1)];
n3 = 1:n+m-1
for i=1:n+m-1
    Y(i)=0
    for j=1:m
        if(i-j+1>0)
            Y(i)=Y(i)+X(j)*H(i-j+1);
        else
        end
    end
end
stem(n3,Y);
xlabel('n->');
ylabel('y(n)->');
title('Convolution');