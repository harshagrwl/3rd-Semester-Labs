recObj = audiorecorder
disp('Start speaking')
recordblocking(recObj, 5);
disp('End of recording');
play(recObj);