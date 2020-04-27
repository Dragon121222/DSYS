using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;

public class DCLIENTTCP : DOBJ {

	Int32 serverPort;
	string serverIP;

	TcpClient client; 
	NetworkStream stream; 

    public void defaultSetup() { 
	    serverPort = 50000;
		serverIP = "192.168.0.3"; 
	    client = new TcpClient(serverIP, serverPort);
	    stream = client.GetStream();
    }

    public void sendMsg(byte[] data) { 
	    stream.Write(data, 0, data.Length);
    }

    public void readMsg() { 
	    byte[] data = new Byte[32768];
	    String responseData = String.Empty;
	    Int32 bytes = stream.Read(data, 0, data.Length);
	    responseData = System.Text.Encoding.ASCII.GetString(data, 0, bytes);
	    Console.WriteLine("Received: {0}", responseData);         
    }

    public void close() { 
	    stream.Close();         
	    client.Close();   	
    }

	public void test() { 
		defaultSetup(); 
		sendMsg(Encoding.ASCII.GetBytes("Hello there")); 
		readMsg(); 
		close(); 
	}

	public void stressTest() { 
		string msg = null; 
		defaultSetup(); 
		for(int i = 0; i < 5000; i++) { 
			msg += i.ToString(); 
			sendMsg(Encoding.ASCII.GetBytes(msg)); 
			readMsg(); 
		}
		close(); 
	}









}


