using System;
using System.IO;
using System.Globalization;

class DFILE : DOBJ {

    string path; 
    StreamWriter sw; 

    public void defaultSetup() { 
        setPath("DLOG/D.log"); 
    }

    public void setPath(string p) { 
        path = p; 
    }

    public void createFile() { 
        if(!File.Exists(path)) {
            using(sw = File.CreateText(path)) { 

            } 
        } else { 
            Console.WriteLine("File already exists.");         
        }
    }

    public void appendFile(string msg) { 
        if(!File.Exists(path)) {
            Console.WriteLine("File doesn't exists.");         
        } else { 
            using(sw = File.AppendText(path)) {
                sw.WriteLine(msg);
            }   
        }
    }

    public void readFile() { 
        using (StreamReader sr = File.OpenText(path)) {
            string s;
            while ((s = sr.ReadLine()) != null) {
                Console.WriteLine(s);
            }
        }
    }

    new public void demo() { 

        DateTime localDate = DateTime.Now;
        var culture = new CultureInfo("en-US");
        string date = localDate.ToString(culture); 

        setPath("DLOG/Demo.log"); 
        createFile(); 
        appendFile("Demo ran on: " + date); 
        readFile(); 
    }
}