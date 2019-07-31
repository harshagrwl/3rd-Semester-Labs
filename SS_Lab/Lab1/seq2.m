clc;
n = input('Enter the value of n  ');
x = -n:n;
x1 = sin(0.6*pi*x + 0.6*pi);
x2 = 2*cos(1.1*pi*x - 0.5*pi);
x3 = mod(x,6);

figure(1);
stem(x,x1);
figure(2);
stem(x,x2);
figure(3);
stem(x,x3);


xticks([-3*pi -2*pi -pi 0 pi 2*pi 3*pi])
xticklabels({'-3\pi','-2\pi','-\pi','0','\pi','2\pi','3\pi'})
yticks([-1 -0.8 -0.2 0 0.2 0.8 1])
xlabel('time axis');
ylabel('y-axis');