clear all;
t = 0:0.1:6.28;
y1 = sin(t);
y2 = sin(2*t);
y3 = sin(5*t);
plot(t,y1,'o',t,y2,'--',t,y3);
xticks([-3*pi -2*pi -pi 0 pi 2*pi 3*pi])
xticklabels({'-3\pi','-2\pi','-\pi','0','\pi','2\pi','3\pi'})
yticks([-1 -0.8 -0.2 0 0.2 0.8 1])
xlabel('time axis');
ylabel('y axis');
title('Multiple graphs');