from turtle import *

color('red')

n = 12
phi = 360 / n

for i in range(n):
    forward(100)
    stamp()
    penup()
    goto(0,0)
    penup()
    left(phi)
    pendown()
    
mainloop()