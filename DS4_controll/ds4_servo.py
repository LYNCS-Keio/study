import pygame
import pigpio
pi=pigpio.pi()
pygame.joystick.init()

joystick = pygame.joystick.Joystick(0)


while True:
    updpwn = joystick.get_axis(0)
    if updown == 0 :
        pi.set_servo_pulsewidth(4, 1500)
    elif updown > 0 :
        pi.set_servo_pulsewidth(4, 2000)
    elif updown < 0 :
        pi.set_servo_pulsewidth(4, 1000)

