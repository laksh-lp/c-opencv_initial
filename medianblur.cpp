#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
 
using namespace std;
using namespace cv;
 
int main( int argc, char** argv )
 {
 
     Mat src = imread( "kohli.jpg", 1 );
     Mat dst;
 
     //Apply median filter
     medianBlur ( src, dst, 15 );
     imshow("source", src);
     imshow("result", dst);  
 
     waitKey(0);
     return 0;
 }