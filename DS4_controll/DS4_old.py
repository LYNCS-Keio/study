
import pygame
pygame.init()

# Set the width and height of the screen [width,height]

#Loop until the user clicks the close button.
done = False
# Used to manage how fast the screen updates

# Initialize the joysticks
pygame.joystick.init()
gamen = pygame.display.set_mode((400, 300))
pygame.display.set_caption('hello world')



# -------- Main Program Loop -----------
while done==False:
    # EVENT PROCESSING STEP
    for event in pygame.event.get(): # User did something
        if event.type == pygame.QUIT: # If user clicked close
            done=True # Flag that we are done so we exit this loop

        # Possible joystick actions: JOYAXISMOTION JOYBALLMOTION JOYBUTTONDOWN JOYBUTTONUP JOYHATMOTION
        if event.type == pygame.JOYBUTTONDOWN:
            print("Joystick button pressed.")
        if event.type == pygame.JOYBUTTONUP:
            print("Joystick button released.")


    # DRAWING STEP
    # First, clear the screen to white. Don't put other drawing commands
    # above this, or they will be erased with this command.

    textPrint.reset()
    # Get count of joysticks
    joystick_count = pygame.joystick.get_count()

    textPrint.indent()

    # For each joystick:
    for i in range(joystick_count):
        joystick = pygame.joystick.Joystick(i)
        joystick.init()





# axis1:center axis2:左右(y軸回転) axis5:上下(x軸回転)
        axis1 = int(1000*joystick.get_axis( 1 ))
        axis2 = int(1000*joystick.get_axis( 2 ))
        axis5 = int(1000*joystick.get_axis( 5 ))



        buttonm = joystick.get_button( 2 )
        buttonb = joystick.get_button( 1 )
        button = buttonb + 2*buttonm




    print (axis2,axis2,axis5,button)

# Close the window and quit.
# If you forget this line, the program will 'hang'
# on exit if running from IDLE.
pygame.quit ()