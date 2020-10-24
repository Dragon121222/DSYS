//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************
#include "opencv2/opencv.hpp"

#ifndef __DOPENCV__
#define __DOPENCV__

class DOPENCV { 

	public: 
		 // Constructors / Deconstructors
		 DOPENCV(); 
		~DOPENCV(); 

		int streamWebCam();
		cv::Mat pointWiseCos(cv::Mat IO); 
		cv::Mat pointWiseXCos(cv::Mat IO);

	private: 

}; 



#endif