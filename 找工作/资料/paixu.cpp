function [image] = removeShow(filename)
image1 = imread(filename);
 % figure(2);
%imshow(image1);
val = 1.7;
G = rgb2gray(image1);
theta = -1
[intr, theta] = getIntrinsic(image1, 1, 0.00001, true, true, theta);

mask = intr - G*val;
treshold = 25;
mask(mask<treshold) = 0;
mask(mask>=treshold) = 1;
[mask contours] = smoothShadowMask(image1, mask);

image = removeShadow(image1, mask, 0);
%result=shadowremoval(image1,'basiclightmodel',mask);

%figure(1);
 
%imshow(image);