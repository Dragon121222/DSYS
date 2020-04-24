//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DGLUTWINDOW__
#include "DGLUTWINDOW.h"
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

//=================================================================================================================================
// Constructors / Deconstructors
//=================================================================================================================================
DGLUTWINDOW::DGLUTWINDOW() { 
	std::cout << "\tDGLUTWINDOW ACTIVE\n"; 
	defaultInit(); 
}

DGLUTWINDOW::DGLUTWINDOW(std::string _title) { 
	std::cout << "\tDGLUTWINDOW ACTIVE\n"; 
	defaultInit(); 
	setTitle(_title); 
} 		 

DGLUTWINDOW::~DGLUTWINDOW() { 

}

//=================================================================================================================================
// Initializers
//=================================================================================================================================
void DGLUTWINDOW::initGlut(int argc, char **argv) { 
    glutInit(&argc, argv);
}

void DGLUTWINDOW::defaultInit() { 
	setDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	setWidth(640); 
	setHeight(480); 
}

//=================================================================================================================================
// Main Loops
//=================================================================================================================================
void DGLUTWINDOW::demoMainLoop() { 

    glutInitDisplayMode(getDisplayMode());
    glutInitWindowSize(getWidth(), getHeight());
    glutInitWindowPosition(0, 0);

    window = glutCreateWindow(getCTitle());
    glClearColor(0.45f, 0.45f, 0.45f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.0f);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(50.0, 1.0, 900.0, 11000.0);
        
    glutDisplayFunc(&DrawGLScene);
    glutIdleFunc(&idleGLScene);
    glutReshapeFunc(&resizeGLScene);
    glutKeyboardFunc(&keyPressed);
    glutMotionFunc(&mouseMoved);
    glutMouseFunc(&mouseButtonPressed);

    printInfo();

    glutMainLoop();

}

//=================================================================================================================================
// Draw Methods
//=================================================================================================================================
void DGLUTWINDOW::drawAxis() { 
    // Draw the world coordinate frame
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);  // X-axis
    glVertex3f(  0, 0, 0);
    glVertex3f( 50, 0, 0);
    glColor3ub(0, 255, 0);  // Y-axis
    glVertex3f(0,   0, 0);
    glVertex3f(0,  50, 0);
    glColor3ub(0, 0, 255);  // Z-axis
    glVertex3f(0, 0,   0);
    glVertex3f(0, 0,  50);
    glEnd();
}

//=================================================================================================================================
// Get Methods
//=================================================================================================================================
int DGLUTWINDOW::getDisplayMode() { 
	return displayMode; 
}

std::string DGLUTWINDOW::getTitle() { 
	return title; 
}

const char * DGLUTWINDOW::getCTitle() { 
	return title.c_str(); 
}

int DGLUTWINDOW::getHeight() { 
	return height; 
}

int DGLUTWINDOW::getWidth() { 
	return width; 
}

//=================================================================================================================================
// Set Methods
//=================================================================================================================================
void DGLUTWINDOW::setDisplayMode(int mode) { 
	displayMode = mode; 
}

void DGLUTWINDOW::setTitle(std::string _title) { 
	title = _title; 
}

void DGLUTWINDOW::setHeight(int _height) { 
	height = _height; 
}

void DGLUTWINDOW::setWidth(int _width) { 
	width = _width; 
}











