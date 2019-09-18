from build import ds4py
import time

ds4 = ds4py.DS4_util()
ds4.DS4_init()
try:
    print("Device:", ds4.DS4_GetDeviceName())
    print("Joystick has", ds4.axes, "axes and", ds4.buttons, "buttons.")
    while True:
        print("Axes ", end="")
        for i in range(ds4.axes):
            print(i, ": ", "{:0=6}".format(ds4.DS4_GetAxis(i)), sep='', end='   ')
        print("")

        print("Buttons ", end="")
        for i in range(ds4.buttons):
            print(i, ": ", ds4.DS4_GetButton(i), sep='', end='   ')
        print("")

        time.sleep(0.01)

finally:
    del ds4