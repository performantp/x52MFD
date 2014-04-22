#include "UdpServer.hpp"
UdpServer::UdpServer ()
{
	using boost::asio::ip::udp;
	//instantiate socket
	socket = new udp::socket(io_service, udp::endpoint(udp::v4(), 1234));

}

UdpServer::~UdpServer ()
{
	delete [] socket;

}

std::string UdpServer::fetch(){
	using boost::asio::ip::udp;

    boost::array<char, BUFFER_SIZE> buf;
	
	udp::endpoint remote_endpoint;
	boost::system::error_code error;

	int received = socket->receive_from(boost::asio::buffer(buf), remote_endpoint, 0, error);

	std::string message(buf.begin(), buf.end()-(BUFFER_SIZE-received));

	return message;
}
