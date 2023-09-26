from turtle import *
import math

color('red')
speed(0)

a = 20
phi = 0

while(phi < 2 * math.pi * 10):
    ro = a * phi/2/math.pi
    x = ro*math.cos(phi)
    y = ro*math.sin(phi)
    goto(x, y)
    phi += 0.1
    
mainloop()