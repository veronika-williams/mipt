import math

t = int(input())

for _ in range(t):
    n = int(input())
    fl = 0
    for k in range(2, 200):
        total = 1 + k + k * k
        cur = k * k * k
        while total < n:
            total += cur
            cur *= k
        if total == n:
            print("YES")
            fl = 1
            break
    if fl == 0:
        k = int(-1 + math.sqrt(4 * n - 3)) // 2
        if 1 + k + k * k == n and k > 1:
            print("YES")
        else:
            print("NO")