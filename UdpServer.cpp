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

	std::string s("123.34\t123.34\t123.45\t123.45\n");
	boost::array<char, BUFFER_SIZE> buf;
	boost::array<char, 28 > sendbuf;
	std::copy(s.begin(), s.begin()+s.size(), sendbuf.begin());

	udp::endpoint remote_endpoint;
	boost::system::error_code error;

	int received = socket->receive_from(boost::asio::buffer(buf), remote_endpoint, 0, error);

	socket->send_to(boost::asio::buffer(sendbuf), remote_endpoint, 0, error);

	std::string message(buf.begin(), buf.end()-(BUFFER_SIZE-received));

	return message;
}
