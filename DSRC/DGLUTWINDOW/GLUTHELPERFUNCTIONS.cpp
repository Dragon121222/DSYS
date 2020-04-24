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

DGLUTWINDOW * globalObj = new DGLUTWINDOW("Global Window"); 
int window; 
int mx = -1, my = -1;         // Prevous mouse coordinates
float anglex = 0, angley = 0; // Panning angles
float zoom = 1;               // Zoom factor
bool color = true;            // Flag to indicate to use of color in the cloud

void idleGLScene() {
    glutPostRedisplay();
}

void printInfo() {
    std::cout << "\nAvailable Controls:"              << std::endl;
    std::cout << "==================="                << std::endl;
    std::cout << "Rotate       :   Mouse Left Button" << std::endl;
    std::cout << "Zoom         :   Mouse Wheel"       << std::endl;
    std::cout << "Toggle Color :   C"                 << std::endl;
    std::cout << "Quit         :   Q or Esc\n"        << std::endl;
}

void resizeGLScene(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, (float)width / height, 900.0, 11000.0);
    glMatrixMode(GL_MODELVIEW);
}

void mouseButtonPressed(int button, int state, int x, int y) {

    if (state == GLUT_DOWN) {
        switch (button) {
            case GLUT_LEFT_BUTTON:
                mx = x;
                my = y;
                break;
            case 3:
                zoom *= 1.2f;
                break;
            case 4:
                zoom /= 1.2f;
                break;
        }

    } else if (state == GLUT_UP && button == GLUT_LEFT_BUTTON) {
        mx = -1;
        my = -1;
    }

}

void mouseMoved(int x, int y) {

    if (mx >= 0 && my >= 0) {
        anglex += x - mx;
        angley += y - my;
    }

    mx = x;
    my = y;

}

void keyPressed(unsigned char key, int x, int y) {

    switch (key) {
        case  'C':
        case  'c':
            color = !color;
            break;

        case  'Q':
        case  'q':
        case 0x1B:  // ESC
            glutDestroyWindow(window);
            exit(0);
    }

}

void DrawGLScene() {

    // Pre-processing Stuff here
    // Add loop to run through an arbitrary list of functions. 

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Draw Stuff here
    // Add loop to run through an arbitrary list of functions. 

    globalObj->drawAxis();

    // Place the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(zoom, zoom, 1);
    gluLookAt( -7*anglex, -7*angley, -1000.0,
                     0.0,       0.0,  2000.0,
                     0.0,      -1.0,     0.0 );

    glutSwapBuffers();

}