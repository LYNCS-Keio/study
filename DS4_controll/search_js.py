import pygame

pygame.init()
pygame.joystick.init()

js_num = pygame.joystick.get_count()

joystick = pygame.joystick.Joystick(0)
print(joystick.get_name())
if js_num != 0:
    for index in range(js_num - 1):
        print(pygame.joystick.Joystick.get_name(0))
        print("AAAA")
else:
    print("no js found")

