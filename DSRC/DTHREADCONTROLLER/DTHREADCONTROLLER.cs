using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DTHREADCONTROLLER : MonoBehaviour {

    void Start() {
//        DCLIENTTCP client = new DCLIENTTCP(); 
    	DTHREAD thread = new DTHREAD(); 
    	thread.defaultSetup(); 
    	thread.demo(); 
    }

    void Update() {
        
    }
}
