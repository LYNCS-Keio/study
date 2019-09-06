#include <iostream>
#include <thread>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/ioctl.h>
#include <linux/input.h>

#include "ds4py.h"


DS4_util::DS4_util () {}

DS4_util::~DS4_util () 
{
    running = false;
    update.join();
    close(fd);
    status = false;
} 

int DS4_util::DS4_init ( const char *dir )
{
    if ((fd = open(dir, O_RDONLY)) < 0){
        status = false;
        throw std::runtime_error("Error: Failed opening device file");
    }

    if ((ioctl(fd, JSIOCGVERSION, &version) < -1) ||
    (ioctl(fd, JSIOCGAXES, &axes) < -1) ||
    (ioctl(fd, JSIOCGBUTTONS, &buttons) < -1) ||
    (ioctl(fd, JSIOCGNAME(128), name) < -1)){
        status = false;
        throw std::runtime_error("Error: Failed controlling device");
    }

    axis = (int *)calloc(axes, sizeof(int));
    button = (int *)calloc(buttons, sizeof(int));

    status = true;
    running = true;

    std::thread update(&DS4_util::DS4_update, this);
    update.detach();

    return 0;
    
}

void DS4_util::DS4_update ()
{
    if (status != true) { throw std::runtime_error("Error: Joystick not initialized"); }

    while (running) {
        if (read(fd, &js, sizeof(struct js_event)) != sizeof(struct js_event)) { throw std::runtime_error("Error: Failed reading device file"); }
    
        switch (js.type & ~JS_EVENT_INIT) {
        case JS_EVENT_BUTTON:
            button[js.number] = js.value;
            break;
        case JS_EVENT_AXIS:
            axis[js.number] = js.value;
            break;
        }
    }

}

int DS4_util::DS4_GetDriverVersion ()
{
    if (status != true) { throw std::runtime_error("Error: Joystick not initialized"); }
    return version;

}

char* DS4_util::DS4_GetDeviceName()
{
    if (status != true) { throw std::runtime_error("Error: Joystick not initialized"); }
    return name;

}

int DS4_util::DS4_GetButton ( u_int8_t num )
{
    if (status != true) { throw std::runtime_error("Error: Joystick not initialized"); }
    if ((num < 0) || ( buttons <= num )) { throw std::runtime_error("Error: Argument is invalid"); }

    return button[num];

}

int DS4_util::DS4_GetAxis ( u_int8_t num )
{
    if (status != true) { throw std::runtime_error("Error: Joystick not initialized"); }
    if ((num < 0) || ( axes <= num )) { throw std::runtime_error("Error: Argument is invalid"); }

    return axis[num];

}

u_int8_t DS4_util::DS4_GetNumAxes()
{
    if (status != true) { throw std::runtime_error("Error: Joystick not initialized"); }
    
    return axes;

}

u_int8_t DS4_util::DS4_GetNumButtons()
{
    if (status != true) { throw std::runtime_error("Error: Joystick not initialized"); }

    return buttons;
    
}

/**
int main ()
{
    const char *filename = "/dev/input/js0";
    DS4_util ds;
    ds.DS4_init(filename);

    while(1)
    {
        std::cout << ds.DS4_GetAxis(3) << std::endl;

    }

}
**/