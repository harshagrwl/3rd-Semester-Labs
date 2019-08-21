clc;
t = 0:.1:50;
y = 0*t;
for x=1:10000
    y = y + sin(-x*t)/x;
end
plot(t,y);