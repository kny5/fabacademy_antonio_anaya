import asciimatics
import pyfiglet

text = "Hi this is my personal website for the Fabcademy program."

ascii_text = pyfiglet.figlet_format(text)

# print(text)

from asciimatics.effects import Cycle, Stars
from asciimatics.renderers import FigletText
from asciimatics.scene import Scene
from asciimatics.screen import Screen
import time
def demo(screen):
    effects = [
        Cycle(
            screen,
            FigletText("FABACADEMY", font='big'),
            int(screen.height / 2 - 8)),
        Cycle(
            screen,
            FigletText("AGRILAB", font='big'),
            int(screen.height / 2 + 3)),
        Stars(screen, 200)
    ]
    screen.play([Scene(effects, 500)])

print(text)
time.sleep(3)	
Screen.wrapper(demo)
