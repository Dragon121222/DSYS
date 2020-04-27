using System;

int fishstick; 

class app {
	
	static void Main(string[] args) {

		if (args.Length == 0) {
			Console.WriteLine("Hello world.");

		} else { 
			if(args[0] == "UDPclientDemo") { 
				Console.WriteLine("Starting UDP client");
				DCLIENTUDP client = new DCLIENTUDP(); 
				client.test(); 

			} else if(args[0] == "UDPserverDemo") { 
				Console.WriteLine("Starting UDP server");
				DSERVERUDP server = new DSERVERUDP(); 
				server.test(); 

			} else if(args[0] == "TCPserverDemo") { 
				Console.WriteLine("Starting TCP server");
				DSERVERTCP server = new DSERVERTCP(); 
				server.test(); 

			} else if(args[0] == "TCPclientDemo") { 
				Console.WriteLine("Starting TCP client");
				DCLIENTTCP client = new DCLIENTTCP(); 
				client.test(); 

			} else if(args[0] == "TCPserverStressTest") { 
				Console.WriteLine("Starting TCP server");
				DSERVERTCP server = new DSERVERTCP(); 
				server.stressTest(); 

			} else if(args[0] == "TCPclientStressTest") { 
				Console.WriteLine("Starting TCP client");
				DCLIENTTCP client = new DCLIENTTCP(); 
				client.stressTest(); 

			}

		}



	}

}