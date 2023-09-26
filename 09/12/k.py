from turtle import * 
import math


def curve(r):
    penup()
    pendown()
    step = 20
    phi = 360/step/2
    dist = 2*r*math.sin(phi/2*math.pi/180)
    for _ in range(step):
        forward(dist)
        right(phi)
    forward(dist)

color('red')
penup()
goto(-200, 0)
pendown()
left(90)

for _ in range(6):
    curve(50)
    curve(10)

mainloop()