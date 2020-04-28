using System;
using System.Globalization;

public class DOBJ {

	DFILE logger; 
	string name = "null"; 

	public void logSetup() { 

        DateTime localDate = DateTime.Now;
        var culture = new CultureInfo("en-US");
        string date = (localDate.ToString(culture)).Replace(" ", "_"); 

		logger = new DFILE(); 
		logger.setPath("DLOG." + name + "." + date + ".log")
		logger.createFile(); 

	}

	public void setName(string n) { 
		name = n; 
	}

	public void demo() { 
	    Console.WriteLine("Base DOBJ Demo");         
	}

	public void Log(string msg) { 
		Console.WriteLine(name + " : " + msg); 
		logger.appendFile(name + " : " + msg);
	}

}