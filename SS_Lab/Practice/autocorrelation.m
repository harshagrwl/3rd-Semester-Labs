clc;
x = [1 -1 1 -1 1 -1];
y1 = fliplr(x);
l1 = length(x);
l2 = length(y1);
m = l1 + l2 -1;
X = [x,zeros(1,l2-1)];
Y1 = [y1,zeros(1,l1-1)];
for i=1:m
    A(i) = 0;
    for j=1:l1
        if(i-j+1>0)
            A(i) = A(i) + (X(j)*Y1(i-j+1));
        else
        end
    end
end
n = 1:m;
stem(n,A);
ylabel('Value:');
xlabel('Lag:');
disp('Autocorrelation:');y