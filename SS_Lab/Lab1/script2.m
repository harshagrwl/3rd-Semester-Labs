clc; close all; clear all;
n = input('Enter the value of n');
t=0:n-1;
y = ones(1,n);
figure(2);
stem(t,y);
title('unit step');