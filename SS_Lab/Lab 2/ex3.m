fs = 10000;
rec = audiorecorder(fs,8,1);
recordblocking(rec,8);
y = getaudiodata(rec);
sound(y,fs);
% play(rec);