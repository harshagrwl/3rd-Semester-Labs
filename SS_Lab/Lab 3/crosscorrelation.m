clc;
x = [1, 0, 2, 1];
y = [1 1 2 1];
z = xcorr(x,y);
n = 1:length(z);
stem(n,z);
ylabel('Value:');
xlabel('Lag:');
disp('Crosscorrelation:');z