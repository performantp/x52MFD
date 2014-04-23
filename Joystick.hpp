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

class Joystick
{
	public:
		Joystick();                             /* constructor */
		~Joystick();                             /* destructor */
        int *axis;
        int *button;
        int roller_0;
        int roller_1;
        int roller_1_held;

	protected:

	private:
        void handleEvents();
        void handleButtonEvent();

        int joy_fd;
        struct js_event event;
        int number_of_axes;
        int number_of_buttons;
};

#endif
