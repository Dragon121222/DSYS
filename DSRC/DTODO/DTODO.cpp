//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DTODO__
#include "DTODO.h"
#endif

#include <boost/filesystem.hpp>

DTODO::DTODO() { 

}

DTODO::~DTODO() { 

} 

void DTODO::setPath(std::string path) { 
	_path = path; 
}

void DTODO::defaultSetup() { 
	setPath("../../DLOG/DTODOLOG/DSUBJECTS/"); 
}

// Task Managers Get / Set
void DTODO::setSubject(std::string subjectName) { 
	// Create a folder: _path/subjectName
	// If the folder exists already, does nothing.

	std::string subPath = _path + std::string("/") + subjectName; 

	boost::filesystem::path dir(subPath);
	if(boost::filesystem::create_directory(dir)) {
		std::cout << "Success" << "\n";
	}

}

void DTODO::setTask(std::string subjectName, std::string taskName) { 
	// Check to see if _path/subjectName exists. 
	// If not, throw error
	// otherwise:  
	// Create a file: _path/subjectName/taskName
	// If the file exists already, does nothing.	
}

void DTODO::setTaskData(std::string subjectName, std::string taskName, std::string taskData) { 
	// Set data in file: _path/subjectName/taskName = taskData
	// Overwrites data in file even if non-empty
}

std::vector<std::string> DTODO::getSubjects() { 
	// Return _path/* as a vector of strings
}

std::vector<std::string> DTODO::getTasks(std::string subjectName) { 
	// Return _path/subjectName/* as a vector of strings
}

std::string DTODO::getTaskData(std::string subjectName, std::string taskName) { 
	// Return the data in the file _path/subjectName/taskName
}

void DTODO::deleteSubject(std::string subjectName) { 
	// Delete the folder: _path/subjectName
	// Also deletes any files in folder
}

void DTODO::deleteTask(std::string subjectName, std::string taskName) { 
	// Delete the file: _path/subjectName/taskName
}
