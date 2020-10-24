#ifndef __DOPENCV__
#include "DOPENCV.h"
#endif

#include "opencv2/opencv.hpp"
#include <cmath>

DOPENCV::DOPENCV() { 

}

DOPENCV::~DOPENCV() { 

}

int DOPENCV::streamWebCam() {

    cv::VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    cv::Mat frame;
    cv::Mat out;
    cv::namedWindow("edges",1);

    for(;;)
    {
        cap >> frame; 
        out = pointWiseXCos(frame);

        cv::imshow("cos", out);
        if(cv::waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;

}



cv::Mat DOPENCV::pointWiseCos(cv::Mat IO) { 

    cv::Mat Out = cv::Mat(IO.rows,IO.cols,IO.type()); 

    for(int i=0; i<IO.rows; ++i){
        for(int j=0; j<IO.cols; ++j) {
            Out.at<cv::Vec3b>(i,j)[0] = 125*(cos(IO.at<cv::Vec3b>(i,j)[0])+1); 
            Out.at<cv::Vec3b>(i,j)[1] = 125*(cos(IO.at<cv::Vec3b>(i,j)[1])+1); 
            Out.at<cv::Vec3b>(i,j)[2] = 125*(cos(IO.at<cv::Vec3b>(i,j)[2])+1);
        }
    }

    return Out; 

}

cv::Mat DOPENCV::pointWiseXCos(cv::Mat IO) { 

    cv::Mat Out = cv::Mat(IO.rows,IO.cols,IO.type()); 

    for(int i=0; i<IO.rows; ++i){
        for(int j=0; j<IO.cols; ++j) {
            Out.at<cv::Vec3b>(i,j)[0] = 125*(IO.at<cv::Vec3b>(i,j)[0]*cos(IO.at<cv::Vec3b>(i,j)[0]/3)+1); 
            Out.at<cv::Vec3b>(i,j)[1] = 125*(IO.at<cv::Vec3b>(i,j)[1]*cos(IO.at<cv::Vec3b>(i,j)[1]/3)+1); 
            Out.at<cv::Vec3b>(i,j)[2] = 125*(IO.at<cv::Vec3b>(i,j)[2]*cos(IO.at<cv::Vec3b>(i,j)[2]/3)+1);
        }
    }

    return Out; 

}

















