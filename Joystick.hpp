#ifndef  Joystick_INC
#define  Joystick_INC
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdio.h>
#include <linux/joystick.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <thread>
#include <unistd.h>
#include <functional>
#include <map>
#include <vector>

class Joystick
{
	public:
		Joystick();                             /* constructor */
		~Joystick();                             /* destructor */
		enum Event {
			SCROLLWHEEL_UP,
			SCROLLWHEEL_DOWN,
			ROLLER0_UP,
			ROLLER0_DOWN,
			ROLLER1_PRESSUP,
			ROLLER1_PRESSDOWN,
			BUTTON_TOP,
			BUTTON_BOTTOM
		};
		void addCallback(std::function<void()> callback, Event event);
		int *axis;
		int *button;
		int roller_0;
		int roller_1;
		int roller_1_held;
		std::map<Event,std::vector<std::function<void()>>> handlers;

	protected:

	private:
		void callHandlers(Event event);
		void handleEvents();
		void handleButtonEvent();

		int joy_fd;
		struct js_event event;
		int number_of_axes;
		int number_of_buttons;
};

#endif
