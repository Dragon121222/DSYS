//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DGLUTWINDOW__
#define __DGLUTWINDOW__

#ifndef __DOBJ__
#include "../DOBJ/DOBJ.h"
#endif

#include <iostream> 
#include <stdio.h>
#include <arrayfire.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <dirent.h>
#include <math.h>
#include <gtk/gtk.h>
#include <GL/glut.h>
#include <gmodule.h>
#include <sys/socket.h> 
#include <netinet/in.h> 

#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/topological_sort.hpp>
#include <boost/graph/graphviz.hpp>

class DGLUTWINDOW : public DOBJ { 

	public: 
		 //=========================================================================================================================
		 // Constructors / Deconstructors
		 //=========================================================================================================================
		 DGLUTWINDOW(); 
		 DGLUTWINDOW(std::string _title); 		 
		~DGLUTWINDOW(); 

		 //=========================================================================================================================
		 // Initializers
		 //=========================================================================================================================
		 void defaultInit(); 
		 void initGlut(int argc, char **argv); 

		 //=========================================================================================================================
		 // Main Loops
		 //=========================================================================================================================
		 void demoMainLoop(); 

		 //=========================================================================================================================
		 // Draw Methods
		 //=========================================================================================================================
	 	 void drawAxis(); 

		 //=========================================================================================================================
		 // Set Methods
		 //=========================================================================================================================
		 void setDisplayMode(int mode); 
		 void setTitle(std::string _title); 
		 void setWidth(int _width); 
		 void setHeight(int _height);

		 //=========================================================================================================================
		 // Get Methods
		 //=========================================================================================================================
		 std::string getTitle(); 
		 const char * getCTitle(); 
		 int getDisplayMode(); 
		 int getWidth();
		 int getHeight();		

	private: 

		//=========================================================================================================================
		// Settings
		//=========================================================================================================================
		int displayMode; 
		std::string title; 
		int height; 
		int width; 

}; 

extern DGLUTWINDOW * globalObj; 
extern int window;                // Glut window identifier
extern int mx, my;         		  // Prevous mouse coordinates
extern float anglex, angley; 	  // Panning angles
extern float zoom;                // Zoom factor
extern bool color;            	  // Flag to indicate to use of color in the cloud

void idleGLScene(); 
void resizeGLScene(int width, int height); 
void printInfo(); 
void mouseButtonPressed(int button, int state, int x, int y); 
void mouseMoved(int x, int y); 
void keyPressed(unsigned char key, int x, int y); 
void DrawGLScene(); 

#endif