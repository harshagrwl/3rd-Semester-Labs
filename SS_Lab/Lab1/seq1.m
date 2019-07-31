clear all;
t = -3:3;
x = [3 -2 0 1 4 5 2]
y = [0 7 1 -3 4 9 -2];
w = [-5 4 3 6 -5 0 1];

figure(1);
u = x+y;
stem(t,u);

figure(2);
v = x.*w;
stem(t,v);

figure(3);
s = y - w;
stem(t,s);

figure(4);
r = 4.5*y;
stem(t,r);
