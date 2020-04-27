using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

public class DSERVER : DOBJ {
	
//	int port; 

    public void startBroadcastDemo() {

        Socket s = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);

        IPAddress broadcast = IPAddress.Parse("192.168.0.3");

        byte[] sendbuf = Encoding.ASCII.GetBytes("Hello There!");
        IPEndPoint ep = new IPEndPoint(broadcast, 11000);

        s.SendTo(sendbuf, ep);

        Console.WriteLine("Message sent to the broadcast address");

    }

}





