clc;
t = 0:.1:10;
y = 0*t;
for x=1:2:100
    y = y + sin(x*t)/x;
end
plot(t,y);