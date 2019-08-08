 I = imread('/home/student/181IT117/SS_Lab/Lab 2/ex9.png');
 figure, imshow(I)
 J = imnoise(I,'salt & pepper',0.02);
 figure
 imshow(J)
 Kaverage = filter2(fspecial('average',3),J)/255;
 figure
 imshow(Kaverage)