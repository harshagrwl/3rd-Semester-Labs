clc;
x = [1 -1 1 -1 1 -1];
n = 1:6;
m = size(n);
y = autocorr(x);
stem(n,y);
ylabel('Value:');
xlabel('Lag:');
disp('Autocorrelation:');y