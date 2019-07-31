clc; close all; clear all;
n = input('Enter the value of input sequence');
t=0:n;
a=input('Enter the a value');
y = exp(a*t);
figure(4);
stem(t,y);
xlabel('x-axis'); ylabel('y-axis')
title('unit exponential');