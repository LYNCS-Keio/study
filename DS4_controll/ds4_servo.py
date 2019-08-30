import pygame
import pigpio
import time
import sys

pygame.init()
pi=pigpio.pi()
pygame.joystick.init()

while True:
    if pygame.joystick.get_count() < 1:
        print("wait for connect")
        print(pygame.joystick.get_count())
        pygame.joystick.quit()
        time.sleep(0.1)
    else:
        print("connected")
        joystick = pygame.joystick.Joystick(0)
        break

print(joystick.get_name())
joystick.init()
print(joystick.get_numaxes())

try:
    while True:
        # Get the latest events from the system
        hadEvent = False
        events = pygame.event.get()
        # Handle each event individually
        for event in events:
            print("event:{}".format(event.type))
            if event.type == pygame.QUIT:
                # User exit
                pass
            elif event.type == pygame.JOYAXISMOTION:
                # A joystick has been moved
                hadEvent = True
            if hadEvent:
                leftRight = joystick.get_axis(0)

            print(leftRight)


    """
    while True:
        time.sleep(0.01)
        print(joystick.get_axis(0), joystick.get_axis(1),
            joystick.get_axis(2), joystick.get_axis(3), joystick.get_axis(4), joystick.get_axis(5))

        updown = joystick.get_axis(0)
        print(updown)
        if updown == 0 :
            pi.set_servo_pulsewidth(4, 1500)
        elif updown > 0 :
            pi.set_servo_pulsewidth(4, 2000)
        elif updown < 0 :
            pi.set_servo_pulsewidth(4, 1000)
    """
finally:
    sys.exit()