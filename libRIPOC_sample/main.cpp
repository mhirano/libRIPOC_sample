#include <iostream>
#include <opencv2/opencv.hpp>

#include <POC.h>

#pragma comment(lib, "opencv_world343.lib")
#pragma comment(lib, "libripoc.1.0.lib")

using namespace cv;
using namespace std;


int main(int argc, char **argv) {
	Mat img1 = imread("../data/lena.png");
	Mat img2 = imread("../data/lena_x40_y60_r20.png");

	POCOption pocOption(POCMethod::RIPOC, 512, 512);
	POC poc(pocOption);

	POCResult pocResult = poc.calcTrans(img1, img2);

	cout << "pocResult.trans: " << pocResult.trans << endl;
	
	cv::namedWindow("img1");
	cv::namedWindow("img2");
	cv::imshow("img1", img1);
	cv::imshow("img2", img2);
	cv::waitKey(0);
	
	return 0;
}
