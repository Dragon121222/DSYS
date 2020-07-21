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
	af::array test = af::array(200,200); 
	topDownGrad(test,test); 

    af::Window myWindow("topDownGradTest");

	while (!myWindow.close()) {
		myWindow.image(test);
	} 


} 