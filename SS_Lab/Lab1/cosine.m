clc; close all; clear all;
t=-pi:0.01:pi;
y = cos(2*pi*t);
plot(t,y);
xticks([-3*pi -2*pi -pi 0 pi 2*pi 3*pi])
xticklabels({'-3\pi','-2\pi','-\pi','0','\pi','2\pi','3\pi'})
yticks([-1 -0.8 -0.2 0 0.2 0.8 1])
xlabel('time axis');
ylabel('y axis');
title('cosine function');