#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <vector.h>

using namespace cv;

int main()
{

  Mat theFrame = imread("kohli.jpg"); // opencv

  Mat gray,binary,canny_output;
  cvtColor(theFrame, gray, CV_BGR2GRAY);
  threshold(gray, binary, 100, 200, THRESH_BINARY); 
  //imwrite("result.jpg",binary);
  imshow("original",theFrame);
  imshow("Binary",binary);
  int thresh =150;
  Canny(gray, canny_output, thresh, thresh*2, 3 );
  imshow("Canny",canny_output);


  waitKey(0);
  return 0;
}