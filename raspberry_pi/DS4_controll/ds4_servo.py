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
print(joystick.get_numbuttons())

try:
    while True:
        time.sleep(1)
        print(joystick.get_button(0), joystick.get_button(1),
          joystick.get_button(2), joystick.get_button(3), joystick.get_button(4), joystick.get_button(5))
        
finally:
    sys.exit()