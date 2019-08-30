
import pygame
pygame.init()

# Set the width and height of the screen [width,height]

#Loop until the user clicks the close button.
done = False
# Used to manage how fast the screen updates

# Initialize the joysticks
pygame.joystick.init()




try:
    # -------- Main Program Loop -----------
    while done==False:
        joystick_count = pygame.joystick.get_count()

        # For each joystick:
        for i in range(joystick_count):
            print(i)
            joystick = pygame.joystick.Joystick(i)
            joystick.init()





    # axis1:center axis2:左右(y軸回転) axis5:上下(x軸回転)
            axis1 = int(1000*joystick.get_axis( 1 ))
            axis2 = int(1000*joystick.get_axis( 2 ))
            axis5 = int(1000*joystick.get_axis( 5 ))



            buttonm = joystick.get_button( 2 )
            buttonb = joystick.get_button( 1 )
            button = buttonb + 2*buttonm




        print (axis1,axis2,axis5,button)
finally:
    # Close the window and quit.
    # If you forget this line, the program will 'hang'
    # on exit if running from IDLE.
    pygame.quit ()