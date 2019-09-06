#pragma once
#include <linux/joystick.h>
#include <thread>

class DS4_util
{
    public:
        int version;
        char name[128] = "Unknown";
        
        int *axis;
        int *button;

        struct js_event js;

        DS4_util();
        ~DS4_util();

        int DS4_init( const char *dir );
        int DS4_GetDriverVersion();
        char* DS4_GetDeviceName();
        int DS4_GetAxis( u_int8_t );
        int DS4_GetButton( u_int8_t );
        void DS4_update();

    private:
        int fd;
        bool status = false;
        bool running = false;
        u_int8_t axes, buttons;
        std::thread update;
};