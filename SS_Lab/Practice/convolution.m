x = [2 1 2 1];
h = [1 2 3];
m = length(x);
n = length(h);
X = [x,zeros(1,n-1)];
H = [h,zeros(1,m-1)];
for i=1:n+m-1
    Y(i)=0
    for j=1:m
        if(i-j+1>0)
            Y(i)=Y(i)+X(j)*H(i-j+1);
        else
        end
    end
end
plot(Y);