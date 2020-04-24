using System;

class app {
	
	static void Main(string[] args) {

		if (args.Length == 0) {
			Console.WriteLine("Hello world.");
		} else { 
			if(args[0] == "UDPclientDemo") { 
				Console.WriteLine("Starting UDP client");
				DCLIENT client = new DCLIENT(); 
				client.defaultSetup(); 
				client.startListenerDemo();
			} else if(args[0] == "UDPserverDemo") { 
				Console.WriteLine("Starting UDP server");
				DSERVER server = new DSERVER(); 
				server.startBroadcastDemo();
			}

		}



	}

}