#include "UdpServer.hpp"

UdpServer::UdpServer (int portno)
{
	using boost::asio::ip::udp;
	port = portno;
	//instantiate socket
	socket = new udp::socket(io_service, udp::endpoint(udp::v4(), port));

}

UdpServer::~UdpServer ()
{
	delete [] socket;

}

std::string UdpServer::fetch(){
	using boost::asio::ip::udp;

	boost::array<char, BUFFER_SIZE> buf;


	int received = socket->receive_from(boost::asio::buffer(buf), remote_endpoint, 0, error);

	std::string message(buf.begin(), buf.end()-(BUFFER_SIZE-received));

	return message;
}


UdpClient::UdpClient(int portno){

	using boost::asio::ip::udp;
	port = portno;
	udp::resolver resolver(io_service);

	std::string portstr = std::to_string(port);
	std::cout<<"port: "<<portstr<<std::endl;
	udp::resolver::query query(udp::v4(), "localhost", portstr);

  remote_endpoint = *resolver.resolve(query);
  socket = new udp::socket(io_service);
  socket->open(udp::v4());

}
UdpClient::~UdpClient(){
	socket->close();
	delete [] socket;
}

void UdpClient::send(std::string message){
	boost::array<char, BUFFER_SIZE > sendbuf;
	std::copy(message.begin(), message.begin()+message.size(), sendbuf.begin());

 socket->send_to(boost::asio::buffer(sendbuf), remote_endpoint);
}

