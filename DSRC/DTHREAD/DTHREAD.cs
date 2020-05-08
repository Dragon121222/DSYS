using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Linq; 

public class DTHREAD : DOBJ {

	public DOBJ obj; 

	new public void defaultSetup() { 
		obj = new DOBJ(); 
	}

	new public void demo() { 
		defaultSetup(); 
		Thread thread = new Thread(new ThreadStart(runDemo));
		thread.Start();
	}

	public void runDemo() { 
		obj.demo(); 
	}



}
