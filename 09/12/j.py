from turtle import * 
import math

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
              
color('red')

r = 30

for i in range(4):
    circle(r, r, 0)
    circle(r, -r, 0)
    r += 20

mainloop()