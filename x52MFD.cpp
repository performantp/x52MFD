#include	<stdlib.h>
#include "MsgParser.hpp"
#include "MFD.hpp"
#include "UdpServer.hpp"
#include <iostream>
#include <string>


using namespace std;
	int
main ( int argc, char *argv[] )
{
	MsgParser parser;
	Msg mymsg;
	UdpServer server;
	MfdPage page(mymsg);
	MFD mfd;

	for(;;){ //continuously update the mfd with data from flightgear
		std::vector<Msg> vec = parser.parse(server.fetch()); 
		Msg mymsg2(vec[0]);
		MfdPage page2(mymsg2);
		mfd.setPage(page2);

	}
	
	return EXIT_SUCCESS;
}
