#ifndef __DGRAPHICS__
#include "DGRAPHICS.h"
#endif


DGRAPHICS::DGRAPHICS() { 

}

DGRAPHICS::~DGRAPHICS() { 

}

void DGRAPHICS::topDownGrad(af::array &I, af::array &O) { 

	int width = I.dims(0); 
	int height = I.dims(1); 

	af::array r = af::range(width); 

	af::array grad = af::tile(r,1,height);  

	O = grad; 

} 

void DGRAPHICS::topDownGradTest() { 

	std::cout << "Starting topDownGradTest\n";

	af::array test = af::array(200,200); 
	topDownGrad(test,test); 

    af::Window myWindow("topDownGradTest");

	while (!myWindow.close()) {
		myWindow.image(test);
	} 


} 

void DGRAPHICS::vectorAnalysis(af::array &I, std::string name) { 

	int d0,d1,d2,d3,dn; 

	d0=I.dims(0); 
	d1=I.dims(1); 
	d2=I.dims(2); 
	d3=I.dims(3); 			
	dn=d0*d1*d2*d3; 

	af::array v = af::flat(I); 
	double sum = af::sum<float>(v); 

	std::cout << "vectorAnalysis:\n"
			  << "Name: " << name << "\n" 
			  << "Dims(0): " << d0 << "\n"
			  << "Dims(1): " << d1 << "\n"
			  << "Dims(2): " << d2 << "\n"
			  << "Dims(3): " << d3 << "\n"
			  << "Total Pixel Count: " << dn << "\n" 
			  << "Max: " << af::max<double>(I) << "\n"
			  << "Min: " << af::min<double>(I) << "\n"
			  << "Sum: " << sum << "\n"
			  << "Avg: " << sum/(double)(dn) << "\n"
			  << "Mean: " << af::mean<double>(I) << "\n"
			  << "Type: " << Type(I) << "\n"; 
}

std::string DGRAPHICS::Type(af::array &I) { 

	af::dtype t = I.type(); 

	if(t == 0) { 
		return "f32"; 
	} else if(t == 1) { 
		return "c32"; 
	} else if(t == 2) { 
		return "f64"; 
	} else if(t == 3) { 
		return "c64"; 
	} else if(t == 4) { 
		return "b8";
	} else if(t == 5) { 
		return "s32";
	} else if(t == 6) { 
		return "u32";
	} else if(t == 7) { 
		return "u8";
	} else if(t == 8) { 
		return "s64";
	} else if(t == 9) { 
		return "u64";
	} else if(t == 10) { 
		return "s16";
	} else if(t == 11) { 
		return "u16";
	} else if(t == 12) { 
		return "f16";
	} else { 
		return "Error"; 
	}

}



/*
void DGRAPHICS::countPixle(int index) { 
	double 
}
*/

void DGRAPHICS::vectorAnalysisTest() { 

	std::cout << "Starting vectorAnalysisTest\n"; 

    af::array img_gray = af::loadImage("DPICTURES/tower.jpg",false);  // 1 channel grayscale [0-255]

    vectorAnalysis(img_gray); 



}