#include <tuple>

#include <linux/joystick.h>

class DS4_util
{
    public:
        int version;
        bool status;
        char name[128] = "Unknown";
        
        int *axis;
        int *button;

        struct js_event js;

        ~DS4_util();

        int DS4_init( const char *dir );
        int DS4_update();
        int DS4_GetDriverVersion();
        char* DS4_GetDeviceName();
        int DS4_GetAxis( u_int8_t );
        int DS4_GetButton( u_int8_t );

    private:
        int fd;
        u_int8_t axes, buttons;

};

