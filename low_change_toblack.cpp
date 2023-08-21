#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <cmath>


using namespace cv;
using namespace std;
Mat src = imread("images/dz-1.jpg");
Mat src_hsv;

Mat different_Channels[3];
Mat h, s, v;
Mat r,r_2,r_3,r_4,r_5,r_6,r_7,r_8;
int main()
{
	split(src, different_Channels);
	r = different_Channels[2];
	// Basic threhold example 
	threshold(r, r_2, 0, 255, THRESH_BINARY);
	imshow("r_2", r_2);

	// Thresholding with maxval set to 128
	threshold(r, r_3, 0, 128, THRESH_BINARY);
	imshow("r_3", r_3);

	// Thresholding with threshold value set 127 
	threshold(r, r_4, 127, 255, THRESH_BINARY);
	imshow("r_4", r_4);

	// Thresholding using THRESH_BINARY_INV 
	threshold(r, r_5, 127, 255, THRESH_BINARY_INV);
	imshow("r_5", r_5);

	// Thresholding using THRESH_TRUNC 
	threshold(r, r_6, 127, 255, THRESH_TRUNC);
	imshow("r_6", r_6);

	// Thresholding using THRESH_TOZERO 
	threshold(r, r_7, 127, 255, THRESH_TOZERO);
	imshow("r_7", r_7);

	// Thresholding using THRESH_TOZERO_INV 
	threshold(r, r_8, 127, 255, THRESH_TOZERO_INV);
	imshow("r_8", r_8);

	imshow("r", r);
	imshow("scr", src);
	waitKey();
	return 0;
}