#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
using namespace cv;
using namespace std;

//int ddepth = CV_16S;
float x=0;
float ma=0.0;
int main()
{
	VideoCapture cap(0);

	while(1)
    {
        Mat green,hsv,frame,mask,d1,d2;
        cap >> frame; 
        //GaussianBlur(ds,frame,Size( 7, 7 ), 0, 0 );        
        //imshow("Video", frame);
        //Mat hsv;
        cvtColor(frame,hsv,CV_RGB2HSV);
        //imshow("hsv",hsv);
        //Mat green;
 		inRange(hsv,Scalar(60, 86, 30),Scalar(85, 255, 255),green);
    	//inRange(hsv,Scalar(25, 75, 20),Scalar(45, 255, 255),green);
 		//imshow("green",green);
        int erosion_size = 2;  
       	Mat element = getStructuringElement(cv::MORPH_CROSS,
              cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
              cv::Point(erosion_size, erosion_size) );
       	erode(green,d1,element);  
       	dilate(d1,d2,element);
       	imshow("eandd",d2);
       	
  		
      	vector<vector<Point> > contours;
    	vector<Vec4i> hierarchy;
    	Scalar color = Scalar( 255,255,255 );
    	findContours( d2, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
    	vector<vector<Point> > contours_poly( contours.size() );
    	//vector<Rect> boundRect( contours.size() );
    	vector<Point2f>center( contours.size() );
  		vector<float>radius( contours.size() );
      	vector<Rect> boundRect(contours.size());
      
      	vector<Point2f> mc(contours.size());
      	vector<Moments> mu(contours.size());
      	int j;
      // for(int i = 0; i<contours.size(); i++)
      // { 
      //   mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 ); 
      // }
    	for( int i = 0; i< contours.size(); i++ )
    		{
          		mu[i] = moments( contours[i], false ); 
          		mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 ); 
    			boundRect[i] = boundingRect(contours[i]) ;
        	  	cout<<boundRect[i].width<<endl;
          		if((boundRect[i].width - boundRect[i].height ) < 5)
            		x=boundRect[i].width;
          		else if((boundRect[i].height - boundRect[i].width ) < 5)
            		x=boundRect[i].height;
          		else
            		x=boundRect[i].width;

          		if(x>ma)
          		{
            		ma=x;
            		j=i;
          		}

    			//minEnclosingCircle( contours_poly[i], center[i], radius[i] );
          //minEnclosingCircle( contours_poly[i], center[i], radius[i] );
        		//drawContours( frame, contours, i, color, 2, 8, hierarchy, 0, Point() );
        		//cout<<radius[i];
    		} 
        if(ma>0)
        {
          circle(frame,mc[j],ma,Scalar(250,0,0),1,30);
          //imshow("if",frame);
          
        }   
       	//imshow("hh",frame);
        imshow("final",frame);





        if(waitKey(30) == 'c')
         break;
    }
    return 0;
}