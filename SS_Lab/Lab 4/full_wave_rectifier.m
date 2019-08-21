t=(0:1/60:1); 
A= 169.71;
sig=A*sin(2*pi*50*t);
subplot(211)
plot(sig);
grid
u=1:9;
for l=1:1*60
if sin(2*pi*50*t(l))<=0
    sig(l)= -A*sin(2*pi*50*t(l));
else
    sig(l) = A*sin(2*pi*50*t(l));
end
end
subplot(212)
plot(sig);