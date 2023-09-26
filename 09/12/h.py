from turtle import *
import math

def polygon(n, r):
    if (n < 3):
        print('Fuck you')
        return
    penup()
    goto(0, r)
    pendown()
    phi = 2 * math.pi / n
    dist = 2 * r * math.sin(phi / 2)
    
    right(phi * 180/math.pi/2)
    
    for _ in range(n):
        forward(dist)
        right(phi * 180 / math.pi)
    
    left(phi * 180/math.pi/2)
        
    penup()
    goto(0, 0)
    pendown()

color('red')

r = 20

for i in range(3, 14):
    polygon(i, r)
    r += 20

mainloop()