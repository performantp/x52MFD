#include	<stdlib.h>
#include "MsgParser.hpp"
#include "MFD.hpp"
#include "UdpServer.hpp"
#include "Joystick.hpp"
#include <math.h>
#include <iostream>
#include <string>

enum Mode {COM,NAV,ADF,DME};
#define NUMBER_OF_MODES 4

using namespace std;
	int
main ( int argc, char *argv[] )
{
	MsgParser parser;
	Msg mymsg;
	UdpServer inbound(1234);
	UdpClient outbound(1235);
	MfdPage page(mymsg);
	MFD mfd;
    Mode mode = COM;
    Joystick *js = new Joystick();

	for(;;){ //continuously update the mfd with data from flightgear

        // handle mode switching
        int mode_tmp = js->roller_1_held;
        if (mode_tmp < 0) {
            mode_tmp += (4*(mode_tmp/-4))+4;
        }
        mode_tmp -= 4*(mode_tmp/4);

        mode = static_cast<Mode>(mode_tmp);

        // update page with correct mode
		std::vector<Msg> vec = parser.parse(inbound.fetch());

		//writing com data back to fg for testing purposes
		//outbound.send("123.34\t123.34\t123.45\t123.45\n");

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
