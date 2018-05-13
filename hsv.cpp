#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
 
int main()
{
    Mat image;
    image = imread("kohli.jpg",1);
    Mat hsv;
    cvtColor(image,hsv,CV_RGB2HSV);
    imshow("hsv",hsv);
    waitKey(0);
    return 0;

    
}