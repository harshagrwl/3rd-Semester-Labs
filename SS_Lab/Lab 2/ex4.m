[y,fs] = audioread('/home/student/181IT117/SS_Lab/Lab 2/ex4.wav');
t = 1/fs:1/fs:length(y)/fs;
% sound(y,fs);
plot(t,y);