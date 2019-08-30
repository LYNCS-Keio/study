import pygame

pygame.init()
pygame.joystick.init()

js_num = pygame.joystick.get_count()

if js_num != 0:
    for index in range(js_num - 1):
        joystick = pygame.joystick.Joystick(index)
        print(joystick.get_name(index))
else:
    print("no js found")