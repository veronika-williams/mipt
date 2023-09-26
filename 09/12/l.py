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
    
    
def circle(r, x, y):
    penup()
    goto(x, y + r)
    pendown()
    step = 40
    phi = 360/step
    dist = 2*r*math.sin(phi/2*math.pi/180)
    
    right(phi/2)
    for _ in range(step):
        forward(dist)
        right(phi)
    left(phi/2)
    penup()
    goto(0,0)
    pendown()

color('yellow')
begin_fill()
circle(100, 0, 0)
end_fill()
color('blue')
begin_fill()
circle(20, -40, 40)
end_fill()
begin_fill()
circle(20, 40, 40)
end_fill()
begin_fill()
color('white')
circle(10, -40, 40)
end_fill()
begin_fill()
color('white')
circle(10, 40, 40)
end_fill()
width(7)
color('red')
penup()
goto(30, 0)
pendown()
right(90)
curve(30)

mainloop()