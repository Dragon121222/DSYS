#ifndef __DGRAPHICS__
#include "DGRAPHICS.h"
#endif


DGRAPHICS::DGRAPHICS() { 

}

DGRAPHICS::~DGRAPHICS() { 

}

void DGRAPHICS::topDownGrad(af::array &IO) { 

	int width = IO.dims(0); 
	int height = IO.dims(1); 

	af::array r = af::range(width); 

	IO = af::tile(r,1,height);  

	IO = IO / af::max<float>(IO); 

} 

void DGRAPHICS::sinOpp(af::array &IO,float lambda, float bias) { 

	IO = (af::sin(af::Pi*2*IO*lambda + bias) + 1)/2; 

}

void DGRAPHICS::topDownSin(af::array &IO, float lambda) { 

	topDownGrad(IO); 

	IO = IO*2*af::Pi; 

	IO = lambda*IO; 

	IO = (af::sin(IO) + 1)/2; 

}

void DGRAPHICS::topDownGradTest() { 

	std::cout << "Starting topDownGradTest\n";

	af::array test = af::array(200,200); 

	topDownGrad(test); 

	vectorAnalysis(test); 

    af::Window myWindow("topDownGradTest");

	while (!myWindow.close()) {
		myWindow.image(test);
	} 

} 

void DGRAPHICS::topDownSinTest() { 

	std::cout << "Starting topDownGradTest\n";

	af::array test = af::array(200,200); 

	topDownSin(test); 

	vectorAnalysis(test); 

    af::Window myWindow("topDownGradTest");

	while (!myWindow.close()) {
		myWindow.image(test);
	} 

} 

void DGRAPHICS::ball2D(af::array &IO) { 
	int width = IO.dims(0); 
	int height = IO.dims(1); 

	for(float i = 0; i < width; i++) { 
		for(float j = 0; j < height; j++) { 
			IO(i,j) = ((i/width)*(i/width) + (j/height)*(j/height));
		}
	}
}

void DGRAPHICS::centralWaveGradTest() { 
	
	std::cout << "Starting centralWaveGradTest\n";
    af::Window myWindow("centralWaveGradTest");

	af::array test = af::array(200,200); 
    float t = 0; 

	ball2D(test); 
	af::array b = test; 

	while (!myWindow.close()) {
		b = test; 
		sinOpp(b,3*(sin(t)+1)+5,3*t); 
		myWindow.image(b);
		t += 0.02f; 
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