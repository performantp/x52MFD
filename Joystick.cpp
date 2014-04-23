#include "Joystick.hpp"

Joystick::Joystick() {
    roller_0 = 0;
    roller_1 = 0;
    roller_1_held = 0;


    bool found_x52 = false;
    int joystick_to_try = 0;

    char name_of_joystick[64];

    while (found_x52 == false) {

        char joystick_to_try_char[1];
        sprintf(joystick_to_try_char, "%d", joystick_to_try);

        char path[14] = "/dev/input/js";
        strcat(path,joystick_to_try_char);
        
        if ((joy_fd = open(path,O_RDONLY)) == -1) {
            std::cout<<"failed to find x52 pro"<<std::endl;
        }


        ioctl(joy_fd, JSIOCGNAME(64), &name_of_joystick);

        if (strcmp(name_of_joystick,"Saitek Saitek X52 Pro Flight Control System") == 0) {
            std::cout<<"Found x52 Pro at "<<path<<std::endl;
            found_x52 = true;
        } else {
            close(joy_fd);
            joystick_to_try++;
        }
    }

    ioctl(joy_fd, JSIOCGAXES, &number_of_axes);
    ioctl(joy_fd, JSIOCGBUTTONS, &number_of_buttons);
    axis = (int *) calloc( number_of_axes, sizeof(int));
	button = (int *) calloc( number_of_buttons, sizeof(int));

    std::thread t1(&Joystick::handleEvents, this);
    t1.detach();
}

Joystick::~Joystick() {
    close(joy_fd);
    free(axis);
    free(button);
}


void Joystick::handleEvents() {
    while(1) {
        read(joy_fd, &event, sizeof(struct js_event));

        switch(event.type & ~JS_EVENT_INIT) {
            case JS_EVENT_AXIS:
                axis[event.number] = event.value;
                break;
            case JS_EVENT_BUTTON:
                handleButtonEvent();
                break;
        }
    }
}

void Joystick::handleButtonEvent() {
    button[event.number] = event.value;

    if (event.number == 34 && event.value == 1) {
        roller_0 += 1;
    }

    if (event.number == 35 && event.value == 1) {
        roller_0 -= 1;
    }

    if (event.number == 36 && event.value == 1) {
        if (button[38] == 1) {
            roller_1_held += 1;
        } else {
            roller_1 += 1;
        }
    }

    if (event.number == 37 && event.value == 1) {
        if (button[38] == 1) {
            roller_1_held -= 1;
        } else {
            roller_1 -= 1;
        }
    }
}
