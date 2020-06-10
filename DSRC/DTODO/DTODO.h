//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DTODO__
#define __DTODO__

#include <string>

class DTODO { 

	public: 

		 // Constructors / Deconstructors
		 DTODO(); 
		~DTODO(); 

		 void setPath(std::string path);
		 void defaultSetup(); 

		 // Task Managers Get / Set / Delete
		 void setSubject(std::string subjectName); 
		 void setTask(std::string subjectName, std::string taskName); 
		 void setTaskData(std::string subjectName, std::string taskName, std::string taskData); 

		 std::vector<std::string> getSubjects();
		 std::vector<std::string> getTasks(std::string subjectName);
		 std::string getTaskData(std::string subjectName, std::string taskName);

		 void deleteSubject(std::string subjectName); 
		 void deleteTask(std::string subjectName, std::string taskName); 

	private: 

		int fd; 
		std::string _path; 


}; 



#endif