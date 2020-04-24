//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DKINECT__
#define __DKINECT__

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

#include "/run/media/drake/Seagate Expansion Drive/BackupDesktop/Code/DSYS/DRIVERS/KINECTDRIVERS/libfreenect/wrappers/cpp/libfreenect.hpp"

class DKINECT : public DOBJ { 

	public: 
		 // Constructors / Deconstructors
		 DKINECT(); 
		~DKINECT(); 

		void vecToChr(std::vector<uint8_t> vec, char * c); 

		std::vector<uint8_t> chrToVec(const char * chr);  

		void vecToChrTest(); 

	private: 

}; 



class Mutex {

	public:

	    Mutex() {
	        pthread_mutex_init(&m_mutex, NULL);
	    }

	    void lock() {
	        pthread_mutex_lock(&m_mutex);
	    }

	    void unlock() {
	        pthread_mutex_unlock(&m_mutex);
	    }

	    class ScopedLock {

		    public:
		        ScopedLock(Mutex &mutex) : _mutex(mutex) {
		            _mutex.lock();
		        }

		        ~ScopedLock() {
		            _mutex.unlock();
		        }

		    private:

		        Mutex &_mutex;

    	};

	private:

    	pthread_mutex_t m_mutex;

};


class MyFreenectDevice : public Freenect::FreenectDevice {

	public:

	    MyFreenectDevice(freenect_context *_ctx, int _index)
	        : Freenect::FreenectDevice(_ctx, _index),
	          m_buffer_video(freenect_find_video_mode(FREENECT_RESOLUTION_MEDIUM, FREENECT_VIDEO_RGB).bytes),
	          m_buffer_depth(freenect_find_depth_mode(FREENECT_RESOLUTION_MEDIUM, FREENECT_DEPTH_REGISTERED).bytes / 2),
	          m_new_rgb_frame(false), m_new_depth_frame(false)
	    {
	        setDepthFormat(FREENECT_DEPTH_REGISTERED);
	    }

	    // Do not call directly, even in child
	    void VideoCallback(void *_rgb, uint32_t timestamp) {
	        Mutex::ScopedLock lock(m_rgb_mutex);
	        uint8_t* rgb = static_cast<uint8_t*>(_rgb);
	        copy(rgb, rgb+getVideoBufferSize(), m_buffer_video.begin());
	        m_new_rgb_frame = true;
	    }

	    // Do not call directly, even in child
	    void DepthCallback(void *_depth, uint32_t timestamp) {
	        Mutex::ScopedLock lock(m_depth_mutex);
	        uint16_t* depth = static_cast<uint16_t*>(_depth);
	        copy(depth, depth+getDepthBufferSize()/2, m_buffer_depth.begin());
	        m_new_depth_frame = true;
	    }

	    bool getRGB(std::vector<uint8_t> &buffer) {
	        Mutex::ScopedLock lock(m_rgb_mutex);
	        
	        if (!m_new_rgb_frame)
	            return false;

	        buffer.swap(m_buffer_video);
	        m_new_rgb_frame = false;

	        return true;
	    }

	    bool getDepth(std::vector<uint16_t> &buffer) {
	        Mutex::ScopedLock lock(m_depth_mutex);
	        
	        if (!m_new_depth_frame)
	            return false;

	        buffer.swap(m_buffer_depth);
	        m_new_depth_frame = false;

	        return true;
	    }

	private:

	    Mutex m_rgb_mutex;
	    Mutex m_depth_mutex;
	    std::vector<uint8_t> m_buffer_video;
	    std::vector<uint16_t> m_buffer_depth;
	    bool m_new_rgb_frame;
	    bool m_new_depth_frame;

};

#endif