using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

public class DCLIENT : DOBJ {

	// Target IP:Port  
    int serverPort;
    string serverIPAddress; 

	IPAddress ipAddress;
	UdpClient listener;
	IPEndPoint groupEP;

	public void defaultSetup() { 
		serverPort = 11000;
		serverIPAddress = "192.168.0.3"; 
		ipAddress = IPAddress.Parse(serverIPAddress);
		listener = new UdpClient(serverPort);
		groupEP = new IPEndPoint(ipAddress, serverPort);
	}

    public void startListenerDemo() {

        try {
            while (true) {
                Console.WriteLine("Waiting for broadcast");

                byte[] bytes = listener.Receive(ref groupEP);

                Console.WriteLine($"Received broadcast from {groupEP} :");
                Console.WriteLine($" {Encoding.ASCII.GetString(bytes, 0, bytes.Length)}");
            }
        } catch (SocketException e) {
            Console.WriteLine(e);
        } finally {
            listener.Close();
        }

    }

}
