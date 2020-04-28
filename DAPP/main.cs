using System;

class app {
	
	static void Main(string[] args) {

		if (args.Length == 0) {
			Console.WriteLine("Hello world.");
		} else { 
			if(args[0] == "UDPclientDemo") { 
				Console.WriteLine("Starting UDP client demo");
				DCLIENTUDP client = new DCLIENTUDP(); 
				client.demo(); 
			} else if(args[0] == "UDPserverDemo") { 
				Console.WriteLine("Starting UDP server demo");
				DSERVERUDP server = new DSERVERUDP(); 
				server.demo(); 
			} else if(args[0] == "TCPserverDemo") { 
				Console.WriteLine("Starting TCP server demo");
				DSERVERTCP server = new DSERVERTCP(); 
				server.demo(); 
			} else if(args[0] == "TCPclientDemo") { 
				Console.WriteLine("Starting TCP client demo");
				DCLIENTTCP client = new DCLIENTTCP(); 
				client.demo(); 
			} else if(args[0] == "TCPserverStressDemo") { 
				Console.WriteLine("Starting TCP server demo");
				DSERVERTCP server = new DSERVERTCP(); 
				server.stressDemo(); 
			} else if(args[0] == "TCPclientStressDemo") { 
				Console.WriteLine("Starting TCP client demo");
				DCLIENTTCP client = new DCLIENTTCP(); 
				client.stressDemo(); 
			} else if(args[0] == "threadDemo") { 
				Console.WriteLine("Starting thread demo");
				DTHREAD thread = new DTHREAD(); 
				thread.demo(); 
			} else if(args[0] == "fileDemo") { 
				Console.WriteLine("Starting file demo");
				DFILE file = new DFILE(); 
				file.demo(); 
			}

		}



	}

}