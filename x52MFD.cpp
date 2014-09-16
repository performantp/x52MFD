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

MsgParser parser;
Msg mymsg;
Msg mymsg2;
UdpServer inbound(1234);
UdpClient outbound(1235);
MfdPage page(mymsg);
MFD mfd;
Mode mode = COM;
Joystick *js = new Joystick();


void buttonTopPressed(){
	mfd.disableUpdate();
	std::cout<<"top button pressed."<<std::endl;
	//TODO: handle different modes
	outbound.send(mymsg2.toString()); 
	mfd.enableUpdate();
}
void buttonBottomPressed(){

	std::cout<<"callback called"<<std::endl;
}

using namespace std;
	int
main ( int argc, char *argv[] )
{

	js->addCallback(&buttonTopPressed,Joystick::BUTTON_TOP);

	for(;;){ //continuously update the mfd with data from flightgear

		// handle mode switching
		int mode_tmp = js->roller_1_held;
		if (mode_tmp < 0) {
			mode_tmp += (NUMBER_OF_MODES*(mode_tmp/-NUMBER_OF_MODES))+NUMBER_OF_MODES;
		}
		mode_tmp -= NUMBER_OF_MODES*(mode_tmp/NUMBER_OF_MODES);

		mode = static_cast<Mode>(mode_tmp);

		// update page with correct mode
		std::vector<Msg> vec = parser.parse(inbound.fetch());

		//writing com data back to fg for testing purposes
		//outbound.send("111.11\t111.11\t111.11\t111.11\t222.22\t222.22\t222.22\t222.22\t333.33\t333.33\t333.33\t333.33\t444.44"); 


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
