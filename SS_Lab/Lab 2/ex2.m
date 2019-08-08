myvoice = audiorecorder;
disp('Start speaking');
recordblocking(myvoice, 10);
disp('End of recording. Playing back...');
play(myvoice);