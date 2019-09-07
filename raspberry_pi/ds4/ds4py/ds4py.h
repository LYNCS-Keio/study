#pragma once
#include <linux/joystick.h>
#include <thread>

constexpr u_int8_t axes_map_size = ABS_MAX + 1;
constexpr u_int8_t buttons_map_size = 0x2FF - BTN_MISC + 1;

class DS4_util
{
    public:
        DS4_util();
        ~DS4_util();

        int DS4_init( const char *dir );
        int DS4_GetDriverVersion();
        char* DS4_GetDeviceName();
        int DS4_GetAxis( u_int8_t );
        int DS4_GetButton( u_int8_t );
        u_int8_t DS4_GetNumAxes();
        u_int8_t DS4_GetNumButtons();
        u_int8_t* DS4_GetAxesMap();
        u_int16_t* DS4_GetButtonsMap();

    private:
        int fd;

        u_int8_t axes, buttons;

        u_int8_t axes_map[axes_map_size];
        u_int16_t buttons_map[buttons_map_size];

        int version;
        char name[128] = "Unknown";
        
        int *axis;
        int *button;

        struct js_event js;

        bool status = false;
        bool running = false;

        std::thread update_thread;

        void update_value();
        int getaxmap();
        int getbtmap();

};