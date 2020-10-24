//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DXM__
#include "DXM.h"
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

#include <glog/logging.h>

//using std::unique_ptr;

/*

DXM::DXM() { 

} 

DXM::~DXM() { 

}
*/

std::unique_ptr<DXM> DXM::Create() {

	std::cout << "Create:\n";

	// 1. Open X display.
	Display* display = XOpenDisplay(nullptr);

	if (display == nullptr) {
		std::cout << "Failed to create display\n";
		return nullptr;
	}

	// 2. Construct DXM instance.
	return std::unique_ptr<DXM>(new DXM(display));

}

DXM::DXM(Display* display) { //: , root_(DefaultRootWindow(display_)) {
	display_ = XOpenDisplay(NULL);
	root_ = DefaultRootWindow(display_);
}

DXM::~DXM() {
	XCloseDisplay(display_);
}

void DXM::Run() {

	// 1. Initialization.
	//   a. Select events on root window. Use a special error handler so we can
	//   exit gracefully if another window manager is already running.
//	wm_detected_ = false;

//	XSetErrorHandler(&DXM::OnWMDetected);
	XSelectInput(display_, root_, SubstructureRedirectMask | SubstructureNotifyMask);

	XSync(display_, false);

//	if (wm_detected_) {
//		std::cout << "Detected another window manager on display " << XDisplayString(display_);
//		return;
//	}

	//   b. Set error handler.
	XSetErrorHandler(&DXM::OnXError);

	for (;;) {
	// 1. Get next event.
		XEvent e;
		XNextEvent(display_, &e);
		std::cout << "Received event: ";
/*
		// 2. Dispatch event.
		switch (e.type) {
			case CreateNotify:
//				CreateNotify(e.xcreatewindow);
			break;
			case DestroyNotify:
//				DestroyNotify(e.xdestroywindow);
			break;
			case ReparentNotify:
//				ReparentNotify(e.xreparent);
			break;

			default:
//			LOG(WARNING) << "Ignored event";
		}
*/
	}

}

/*
int DXM::OnWMDetected(Display* display, XErrorEvent* e) {

	// In the case of an already running window manager, the error code from
	// XSelectInput is BadAccess. We don't expect this handler to receive any
	// other errors.
//	CHECK_EQ(static_cast<int>(e->error_code), BadAccess);

	// Set flag.
	wm_detected_ = true;
	// The return value is ignored.
	return 0;
}
*/

int DXM::OnXError(Display* display, XErrorEvent* e) { /* Print e */ }




