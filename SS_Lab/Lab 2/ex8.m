I = imread('/home/student/181IT117/SS_Lab/Lab 2/ex8_1.png');
J = imread('/home/student/181IT117/SS_Lab/Lab 2/ex8_2.png');
K = imadd(I,J,'uint8');
figure, imshow(I);
figure, imshow(J);
figure, imshow(K,[]);