#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <cmath>


using namespace cv;
using namespace std;
Mat src = imread("images/dz-7.jpg");
Mat src_hsv;
Mat diffChannel[3];
int main() {
	cvtColor(src, src_hsv, COLOR_BGR2HSV);
	split(src_hsv, diffChannel);
	int sum = cv::sum(diffChannel[2])[0];
	int count = diffChannel[2].rows * diffChannel[2].cols;

	// ���������� �������� ��������
	double average = static_cast<double>(sum) / count;

	std::cout << "���� �������: " << average << std::endl;
	waitKey(0);
	return 0;
}