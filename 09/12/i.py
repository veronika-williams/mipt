from turtle import *
import math

def circle(r, x, y):
    penup()
    goto(x, y + r)
    pendown()
    step = 40
    phi = 360/step
    dist = 2*r*math.sin(phi/2*math.pi/180)
    
    for _ in range(step):
        forward(dist)
        right(phi)
          
color('red')  

r = 50
n = 5
phi = 0
step = 360 / n

while(phi < 360):
    x = r * math.cos(phi*math.pi/180)    
    y = r * math.sin(phi*math.pi/180)
    circle(r, x, y)
    phi += step

mainloop()