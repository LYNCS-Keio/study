#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <tuple>

#include <sys/ioctl.h>
#include <linux/input.h>

#include "ds4.h"


int DS4_util::DS4_init ( const char *dir )
{
    if ((fd = open(dir, O_RDONLY)) < 0){
        status = false;
        return -1; 
    }

    if ((ioctl(fd, JSIOCGVERSION, &version) < -1) ||
    (ioctl(fd, JSIOCGAXES, &axes) < -1) ||
    (ioctl(fd, JSIOCGBUTTONS, &buttons) < -1) ||
    (ioctl(fd, JSIOCGNAME(128), name) < -1)){
        status = false;
        return -1;
    }

    axis = (int *)calloc(axes, sizeof(int));
    button = (int *)calloc(buttons, sizeof(int));

    status = true;
    
}

int DS4_util::DS4_update ()
{
    if (status != true) { return -1; }
    if (read(fd, &js, sizeof(struct js_event)) != sizeof(struct js_event)) { return -1; }
    
    switch (js.type & ~JS_EVENT_INIT) {
    case JS_EVENT_BUTTON:
        button[js.number] = js.value;
        break;
    case JS_EVENT_AXIS:
        axis[js.number] = js.value;
        break;
    }

}

int DS4_util::DS4_GetDriverVersion ()
{
    return version;

}

char* DS4_util::DS4_GetDeviceName()
{
    return name;

}

int DS4_util::DS4_GetButton ( u_int8_t num )
{
    if (status != true) { return -1; }
    if ((num < 0) || ( buttons <= num )) { return -1; }

    return button[num];

}

int DS4_util::DS4_GetAxis ( u_int8_t num )
{
    if (status != true) { return -1; }
    if ((num < 0) || ( axes <= num )) { return -1; }

    return axis[num];

}

DS4_util::~DS4_util ()
{
    close(fd);
}


int main ()
{ 
    const char *filename = "/dev/input/js0";

    DS4_util ds41;
    ds41.DS4_init(filename);
    std::cout << ds41.DS4_GetDeviceName() << std::endl;
    
    while(1)
    {
        ds41.DS4_update();
        std::cout << ds41.DS4_GetButton(2) << std::endl;

    }
    
}
