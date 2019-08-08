 I = imread('/home/student/181IT117/SS_Lab/Lab 2/ex9.png');
 figure, imshow(I)
 J = imnoise(I,'salt & pepper',0.02);
 figure
 imshow(J)
 Kmedian = medfilt2(J);
 imshowp(Kmedian)
% openExample('images/CompareResultsOfAveragingFilterAndMedianFilterExample')