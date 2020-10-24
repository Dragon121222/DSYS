
//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************


#ifndef __DML__
#define __DML__

#ifndef __DOBJ__
#include "../DOBJ/DOBJ.h"
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

class DML : public DOBJ { 

	typedef void (*DOP)(af::array &, af::array &, af::array &);

	public: 

		DML(); 
		~DML(); 

		//Active Functions
		void fire(af::array& input, af::array& output); 
		void Optimization_Domain_Random_Searching(std::vector<af::array> & inputVectors, std::vector<af::array> & labelVectors); 
		void Optimization_Simple_Quasisecant_Method(std::vector<af::array> & inputVectors, std::vector<af::array> & labelVectors);
		void Find_Quasisecant(std::vector<af::array> & dir, std::vector<af::array> & qsec, float h = 0.1f, float d = 0.1f ); 

		//Std vector array Functions
		float ObjectiveOperator(std::vector<af::array> & inputVectors,std::vector<af::array> & labelVectors); 
		void Generate_Kernel_Translation_Vector(std::vector<af::array> & translation); 

		//Architecture Operations
		void appendOp(DOP op, std::string name, int inputDim, int outputDim); 
		void formNeuralNet(int inputDim, int outputDim); 	

		//Test Functions
		void v_conv(af::array & input, af::array & output); 
		void generateData(int size,int inputDim,int outputDim, std::vector<af::array> & inputVectors,std::vector<af::array> & labelsVectors); 

		//Debug Functions
		void debugMachine(); 

	private: 

		std::vector<DOP> DOPList; 
		std::vector<std::string> DNameList;
		std::vector<int> DInputDimList; 
		std::vector<int> DOutputDimList; 		

		std::vector<af::array> DKernel; 

};

void v_add(af::array & input, af::array & output, af::array & kernel); 
void v_matrix(af::array & input, af::array & output, af::array & kernel); 
void v_atan(af::array & input, af::array & output, af::array & kernel); 

void Add_Std_Vector_Array(std::vector<af::array> & in_1, std::vector<af::array> & in_2, std::vector<af::array> & out); 
void Add_Std_Vector_Array(std::vector<af::array> & in, std::vector<af::array> & in_out); 
void Add_Std_Vector_Array(float constant, std::vector<af::array> & in_out); 
float Norm_Std_Vector_Array(std::vector<af::array> & in_out); 

void Scale_Std_Vector_Array(float sclr, std::vector<af::array> & in_1, std::vector<af::array> & out);
void Scale_Std_Vector_Array(float sclr, std::vector<af::array> & in_out); 

#endif