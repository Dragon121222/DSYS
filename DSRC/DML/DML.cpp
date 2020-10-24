//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DML__
#include "DML.h"
#endif

#include <vector>
#include <iostream> 
#include <stdio.h>
#include <arrayfire.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <dirent.h>
#include <math.h>
#include <gmodule.h>
#include <algorithm>

DML::DML() { 

} 

DML::~DML() { 

}

void DML::appendOp(DOP op, std::string name, int inputDim, int outputDim) { 	

	DOPList.push_back(op); 
	DNameList.push_back(name); 
	DInputDimList.push_back(inputDim); 
	DOutputDimList.push_back(outputDim); 

	if(name == "v_add") { 
		DKernel.push_back(af::randu(inputDim));
	} else if(name == "v_matrix") { 
		DKernel.push_back(af::randu(outputDim,inputDim));
	} else if(name == "v_atan") { 
		DKernel.push_back(af::randu(inputDim));
	} else { 
		std::cout << "Error, operator not recognized.\n"; 
	}

}

void DML::fire(af::array& input, af::array& output) { 
	af::array tmp = input; 
	auto ker = DKernel.begin(); 
	for(auto it = DOPList.begin(); it != DOPList.end(); ++it) { 
		(*it)(tmp,tmp,(*ker));
		++ker;  
	}
	output = tmp; 
} 

void DML::formNeuralNet(int inputDim, int outputDim) { 

	int secondLevel = (int)floor(((double)(inputDim + outputDim))/2);

    appendOp(v_matrix, "v_matrix", inputDim,    secondLevel); 
    appendOp(v_add,    "v_add",    secondLevel, secondLevel);     
    appendOp(v_atan,   "v_atan",   secondLevel, secondLevel);

    appendOp(v_matrix, "v_matrix", secondLevel, outputDim); 
    appendOp(v_add,    "v_add",    outputDim,   outputDim);     
    appendOp(v_atan,   "v_atan",   outputDim,   outputDim);    

}

float DML::ObjectiveOperator(std::vector<af::array> & inputVectors,
							 std::vector<af::array> & labelVectors) { 

	float sum = 0; 
	auto labelVector = labelVectors.begin();
	af::array output; 
	for(auto inputVector = inputVectors.begin(); inputVector != inputVectors.end(); ++inputVector) { 
		fire(*inputVector,output); 
		sum += af::norm(output - *labelVector); 
		++labelVector; 
	}	
	return sum; 

}

void DML::debugMachine() { 
	auto inDim = DInputDimList.begin(); 
	auto outDim = DOutputDimList.begin(); 
	auto ker = DKernel.begin(); 	
	int layer = 0; 
	std::string tag; 
	for(auto it = DNameList.begin(); it != DNameList.end(); ++it) { 
		std::cout << "*************************************************\n"
			 << "Operator Name:  " << (*it) << "\n"
			 << "Input Dimsion:  " << (*inDim) << "\n"
			 << "Output Dimsion: " << (*outDim) << "\n";
		tag = "Kernel Layer " + std::to_string(layer); 
		af::print(tag.c_str(),(*ker)); 
		++layer; 
		++inDim; 
		++outDim; 
		++ker; 
 	}
}


//Test Opps
void DML::v_conv(af::array & input, af::array & output) { 

	for(int i = 0; i < output.dims(0); i++) { 
		output(i) = af::dot(input,af::shift(input,i)); 
	}

}

void DML::generateData(int size,
					   int inputDim,
					   int outputDim, 
					   std::vector<af::array> & inputVectors,
					   std::vector<af::array> & labelsVectors) { 

    af::array y = af::array(outputDim);
    af::array x = af::array(inputDim); 

	for(int i = 0; i < size; ++i) { 

		x = af::randu(inputDim); 

    	v_conv(x,y);	    

    	inputVectors.push_back(x); 
    	labelsVectors.push_back(y); 

	}

}

void DML::Optimization_Domain_Random_Searching(std::vector<af::array> & inputVectors,
											   std::vector<af::array> & labelVectors) { 

	std::vector<af::array> prevKernel = DKernel; 

	float score = 1000000000; 
	float prevScore; 
	float size; 
	float prevSize = 1; 

	float sizeScalar = 2; 

	prevScore = ObjectiveOperator(inputVectors,labelVectors); 
	prevKernel = DKernel; 

	float count = 0.0f; 

	while(score > 1.0f) { 

		size = ( sizeScalar*prevSize*cos(count/100) ); 

		std::vector<af::array> translation; 
		Generate_Kernel_Translation_Vector(translation); 

		Scale_Std_Vector_Array(size ,translation); 
		Add_Std_Vector_Array(translation,DKernel); 
		DKernel = translation; 
		
		score = ObjectiveOperator(inputVectors,labelVectors); 

		if(score < prevScore) { 

			prevKernel = DKernel; 
			prevScore = score; 
			std::cout << "New Score: " << score << "\n"; 
			count = 0; 
			prevSize = size;
			sizeScalar = sizeScalar/1000;  

		} else { 
			DKernel = prevKernel; 
		}

		if(sizeScalar < 10) { 
			sizeScalar *= 1.01f; 
		}

		count += 0.01f; 

	}

}


// Creates Kernel Vector on the boundary of the ball in the Kernel Space. 
void DML::Generate_Kernel_Translation_Vector(std::vector<af::array> & translation) { 

	af::array t; 

	for(auto kernelVector = DKernel.begin(); kernelVector != DKernel.end(); ++kernelVector) { 
		t = af::randu( (*kernelVector).dims(0),(*kernelVector).dims(1),(*kernelVector).dims(2),(*kernelVector).dims(3) ); 
//		t = t / af::norm(t); 
		translation.push_back( t );
	} 

	Scale_Std_Vector_Array(2,translation); 
	Add_Std_Vector_Array(-1,translation); 
	float n = Norm_Std_Vector_Array(translation); 
	Scale_Std_Vector_Array(n,translation);

}



void DML::Optimization_Simple_Quasisecant_Method(std::vector<af::array> & inputVectors, std::vector<af::array> & labelVectors) { 

	float h = 0.1f; 
	float c = 0.1f; 
	float d = 0.1f; 

	std::vector<af::array> x = DKernel; 

	std::vector<af::array> D; 	
	Generate_Kernel_Translation_Vector(D); 


}

void DML::Find_Quasisecant(std::vector<af::array> & dir, std::vector<af::array> & qsec, float h , float d) { 



}


