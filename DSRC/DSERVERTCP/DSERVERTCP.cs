using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;		

public class DSERVERTCP : DOBJ {

	//Server Variables
    TcpListener server;   
	Int32 serverPort;
	IPAddress serverIP;

	//Connected Client Variables
	TcpClient client; 
	NetworkStream stream; 

	public void defaultSetup() { 
		serverPort = 50000; 
		serverIP = IPAddress.Parse("192.168.0.3"); 
		server = new TcpListener(serverIP, serverPort);
		server.Start();
	}

	public void startListening() { 
        client = server.AcceptTcpClient();            
        Console.WriteLine("Connected!");
        stream = client.GetStream();
	}

	public void readMsg() { 
		Byte[] bytes = new Byte[32768];
		String data = null;
		int i = stream.Read(bytes, 0, bytes.Length); 
		data = System.Text.Encoding.ASCII.GetString(bytes, 0, i);
		Console.WriteLine("Received: {0}", data);
	}

	public void sendMsg(byte[] msg) { 
		stream.Write(msg, 0, msg.Length);
	}

	public void close() { 
		client.Close();
		server.Stop();
	}

	new public void demo() { 
		defaultSetup(); 
		startListening(); 
		readMsg(); 
		sendMsg(Encoding.ASCII.GetBytes("General Kenobi")); 
		close(); 
	}

	public void stressDemo() { 
		string msg = "Received"; 
		defaultSetup(); 
		startListening(); 
		for(int i = 0; i < 5000; i++) { 
			readMsg(); 
			sendMsg(Encoding.ASCII.GetBytes(msg)); 
		}
		close(); 
	}

}


