clc;
clear all;
x = input('Enter the input sequence = ');
N = length(x);
for k = 1:N
    y(k) = 0;
    for n = 1:N
        y(k) = y(k)+x(n)*exp(-1i*2*pi*(k-1)*(n-1)/N);
    end
end

t = 0:N-1;
subplot(1,2,1);
stem(t,x);
ylabel('Amplitude ---->');
xlabel('n ---->');
title('Input Sequence');
grid on;
magnitude = abs(y); 
disp('FFT Sequence = ');
disp(magnitude);

t = 0:N-1;
subplot(1,2,2);
stem(t,magnitude);
ylabel('Amplitude ---->');
xlabel('K ---->');
title('FFT Sequence');