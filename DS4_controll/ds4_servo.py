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


finally:
    sys.exit()