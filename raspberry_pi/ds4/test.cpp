#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/ioctl.h>

#include <linux/input.h>
#include <linux/joystick.h>

#define NAME_LENGTH 128

int main ()
{

    int i;
    int fd;
    int version;
    unsigned char axes, buttons;
    char name[NAME_LENGTH] = "Unknown";
    
    int *axis;
    char *button;

    struct js_event js;

    if ((fd = open("/dev/input/js0", O_RDONLY)) < 0){
        std::cout << "error opening device" << std::endl;
        return 1; 
    }
    ioctl(fd, JSIOCGVERSION, &version);
    ioctl(fd, JSIOCGAXES, &axes);
    ioctl(fd, JSIOCGBUTTONS, &buttons);
    ioctl(fd, JSIOCGNAME(NAME_LENGTH), name);

    axis = (int *)calloc(axes, sizeof(int));
    button = (char *)calloc(buttons, sizeof(char));
    
    while (1)
    {
        if (read(fd, &js, sizeof(struct js_event)) != sizeof(struct js_event)) {
           std::cout << "error reading" << std::endl;
           return 1;
        }
        
        switch (js.type & ~JS_EVENT_INIT) {
        case JS_EVENT_BUTTON:
            button[js.number] = js.value;
            break;
        case JS_EVENT_AXIS:
            axis[js.number] = js.value;
            break;
        }

        std::cout << std::hex << js.time << " ";

        if (axes) {
            printf("Axes: ");
            for (i = 0; i < axes; i++)
                printf("%2d:%6d ", i, axis[i]);
        }

        if (buttons) {
            printf("Buttons: ");
            for (i = 0; i < buttons; i++)
                printf("%2d:%d ", i, button[i]);
        }

        std::cout << std::endl;

        fflush(stdout);

    }

    
}