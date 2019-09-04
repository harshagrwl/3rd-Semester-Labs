clc;
clear all;
n = -2:2;
y = n.*n;
figure(1);
stem(n,y);
xlabel('n->');
ylabel('y->');
title('Unmodified Function');

m = -3:0.1:3;
z = m.*m;
figure(2);
stem(m,z);
xlabel('n->');
ylabel('y->');
title('Modified Function');