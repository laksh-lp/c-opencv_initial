int main (int argc, char * const argv[])
{
   const string EXT = “.jpg”; // extension of any images 
       if (argc<3) {
       fprintf(stderr, “Usage: motion INPUT_FILE_NAME OUTPUT_FILE_NAME [ObjectSizeSensitivity]\n”);
       exit(1);
    }
    double detected_area; 
    int min_area = atoi(argv[3]);
    Mat kernel_dilate = getStructuringElement(MORPH_RECT, Size(3,3));
    VideoCapture camera(argv[1]);
    Size size2 = Size(1920, 1080);
    int codec = CV_FOURCC(‘M’, ‘P’, ‘E’, ‘G’);
    VideoWriter out(argv[2], codec, 6.0, size2, true);

    Mat result, new_frame, avg, avgconv, frameDelta, thresh;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    camera.read(new_frame);
    avg = Mat::zeros(new_frame.size(), CV_32FC1);
    // 
    while ( 1 ){
        //Take a new image
        camera.read(new_frame);
        if(!new_frame.empty()) { 
        result = new_frame;
        cvtColor(new_frame, new_frame, CV_RGB2GRAY);
        GaussianBlur(new_frame, new_frame, Size(21, 21), 0);
        accumulateWeighted(new_frame, avg, 0.5);
        convertScaleAbs(avg,avgconv);
        absdiff(new_frame,avgconv,frameDelta);
        threshold(frameDelta, thresh, 35, 255, THRESH_BINARY);
        dilate(thresh, thresh, kernel_dilate, Point(-1, -1), 2, BORDER_CONSTANT);
        findContours(thresh, contours, hierarchy, RETR_EXTERNAL,CHAIN_APPROX_SIMPLE, Point(0, 0));

        for(size_t i = 0; i < contours.size(); i++)
         detected_area = contourArea(contours[i]);
                if (detected_area > min_area) {
            out << result;
                }
        }
    else
        {
        camera.open(argv[1]);
         }
       }
      return 0;
}