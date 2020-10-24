//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DML__
#include "DML.h"
#endif

void v_add(af::array & input, af::array & output, af::array & kernel) { 
	output = input + kernel; 
}

void v_matrix(af::array & input, af::array & output, af::array & kernel) { 
	output = af::matmul(kernel,input); 
}

void v_atan(af::array & input, af::array & output, af::array & kernel) { 
	output = af::atan(input)*kernel;  
}


//Adds two vectors without changeing the values in the inputs. 
void Add_Std_Vector_Array(std::vector<af::array> & in_1,
						  std::vector<af::array> & in_2,
						  std::vector<af::array> & out) { 

	auto b = in_2.begin();
	for(auto a = in_1.begin(); a != in_1.end(); ++a) { 
		out.push_back((*a)+(*b)); 
		++b; 
	}

}

//Adds two vectors and changes the values in the output. 
void Add_Std_Vector_Array(std::vector<af::array> & in,
						  std::vector<af::array> & in_out) { 

	auto b = in_out.begin();
	for(auto a = in.begin(); a != in.end(); ++a) { 
		(*b) = (*a)+(*b); 
		++b; 
	}

}

//Adds constant vector in the kernel space to the input. Changes the value of the input. 
void Add_Std_Vector_Array(float constant, std::vector<af::array> & in_out) { 

	for(auto a = in_out.begin(); a != in_out.end(); ++a) { 
		(*a) = (*a)+constant; 
	}

}

//Scales input vector without changing it. 
void Scale_Std_Vector_Array(float sclr, 
							std::vector<af::array> & in,						    
						    std::vector<af::array> & out) { 

	for(auto a = in.begin(); a != in.end(); ++a) { 
		out.push_back((*a)*sclr); 
	}

}

//Scales input vector and changes it. 
void Scale_Std_Vector_Array(float sclr, 
							std::vector<af::array> & in_out) { 

	for(auto a = in_out.begin(); a != in_out.end(); ++a) { 
		(*a) = (*a)*sclr;
	}

}

//Returns euclidean norm of the input vector without changing it. 
float Norm_Std_Vector_Array(std::vector<af::array> & in) { 

	float sum = 0.0f; 

	for(auto a = in.begin(); a != in.end(); ++a) { 
		sum += pow(af::norm((*a)),2); 
	}

	sum = pow(sum,0.5f); 

	return sum; 
}
