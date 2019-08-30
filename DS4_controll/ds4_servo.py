import pygame
import pigpio
import time

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

joystick.init()

while True:
    time.sleep(0.01)
    updown = joystick.get_axis(0)
    print(updown)
    if updown == 0 :
        pi.set_servo_pulsewidth(4, 1500)
    elif updown > 0 :
        pi.set_servo_pulsewidth(4, 2000)
    elif updown < 0 :
        pi.set_servo_pulsewidth(4, 1000)

