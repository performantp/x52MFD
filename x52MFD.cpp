#include	<stdlib.h>
#include "MsgParser.hpp"
#include "MFD.hpp"
#include "UdpServer.hpp"
#include <iostream>
#include <string>

enum Mode {COM,NAV,ADF,DME};

using namespace std;
	int
main ( int argc, char *argv[] )
{
	MsgParser parser;
	Msg mymsg;
	UdpServer server;
	MfdPage page(mymsg);
	MFD mfd;
    Mode mode = COM;

	for(;;){ //continuously update the mfd with data from flightgear
		std::vector<Msg> vec = parser.parse(server.fetch());

		Msg mymsg2;
       
        switch (mode)
        {
            case COM:
                mymsg2 = vec[0];
                break;
            case ADF:
                mymsg2 = vec[1];
                break;
            case NAV:
                mymsg2 = vec[2];
                break;
            case DME:
                mymsg2 = vec[3];
                break;
            default:
                break;
        }

		MfdPage page2(mymsg2);
		mfd.setPage(page2);

	}
	
	return EXIT_SUCCESS;
}
