#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
using namespace cv;
using namespace std;
int main( )
{
	VideoCapture cap(0);
  Size size(500,500);

	while(1)
    {
      Mat frame,mask,dst,st;
      cap >> frame;         
      //imshow("Video", frame);
      Mat hsv;
      cvtColor(frame,hsv,CV_RGB2HSV);
      //imshow("hsv",hsv);
      Mat green;
 		  inRange(hsv,Scalar(29, 86, 6),Scalar(100, 255, 255),green);
 		  //imshow("green",green);
      int erosion_size = 2;  
      Mat element = getStructuringElement(cv::MORPH_CROSS,
        cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
        cv::Point(erosion_size, erosion_size) );
      erode(green,dst,element);  
      dilate(dst,st,element);
      //imshow("eandd",st);
      vector<vector<Point> > contours;
    	vector<Vec4i> hierarchy;
    	Scalar color = Scalar( 255,255,255 );
    	findContours( st, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
    	double area;
<<<<<<< HEAD
      vector<vector<Point> > contours_poly( contours.size() );
      vector<Rect> boundRect( contours.size() );
      vector<Point2f>center( contours.size() );
      vector<float>radius( contours.size() );

      
=======
	vector<vector<Point> > contours_poly( contours.size() );
	vector<Rect> boundRect( contours.size() );
  	vector<Point2f>center( contours.size() );
  	vector<float>radius( contours.size() );
>>>>>>> cc313cdd378546362bf409784e7c0e33eb1731a4
    	if(contours.size()>0)
    	{
    		
    		for( int i = 0; i< contours.size(); i++ )
    		{
<<<<<<< HEAD
          boundRect[i] = boundingRect( Mat(contours_poly[i]) );
          minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
          cout<<radius[i];
          //if(radius[i]>10)
            //{
        
            //}
            //drawContours( frame, contours, i, color, 2, 8, hierarchy, 0, Point() );
          
        		
    		}
=======
			boundRect[i] = boundingRect( Mat(contours_poly[i]) );
       			minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
			if(radius[i]>10)
				{
				
				}
        		//drawContours( frame, contours, i, color, 2, 8, hierarchy, 0, Point() );
    		}    
       		
>>>>>>> cc313cdd378546362bf409784e7c0e33eb1731a4

        //drawContours( frame, contours, i, color, 2, 8, hierarchy, 0, Point() );    
       		
        resize(frame,frame,size);
       	imshow("frame",frame);

    	}
    	





      if(waitKey(30) == 'c')
        break;
    }
    return 0;
}
