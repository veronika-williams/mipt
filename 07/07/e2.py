import math

f = lambda k, m: (k ** (m + 1) - 1) // (k - 1)

def check(n):
    for m in range(2, 60):
        l = 2
        r = 1000000000
        fl = 1
        while l + 1 < r:
            if f(l, m) > n:
                fl = 0
                break
            mid = (l + r) // 2
            if f(mid, m) < n:
                l = mid
            elif f(mid, m) > n:
                r = mid
            else:
                return 1
        if f(l, m) == n or f(r, m) == n:
            return 1
        if fl == 0:
            break
    return 0

t = int(input())

for _ in range(t):
    n = int(input())
    if check(n):
        print("YES")
    else:
        print("NO")