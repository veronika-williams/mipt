import math

def f(k, m):
    return (k ** (m + 1) - 1) // (k - 1)

s = []

maxlimit = 10 ** 18

for k in range(2, 1000001):
    for m in range(3, 64):
        if f(k, m) > maxlimit:
            break
        s.append(f(k, m))

s = sorted(s)

def find(n):
    l = 0
    r = len(s) - 1
    while l <= r:
        mid = (l + r) // 2
        if s[mid] == n:
            return True
        if s[mid] > n:
            r = mid - 1
        else:
            l = mid + 1
    return False

t = int(input())
for _ in range(t):
    n = int(input())
    if find(n):
        print("YES")
    else:
        k = (-1 + int(math.sqrt(4 * n - 3))) // 2
        if k > 1 and 1 + k + k * k == n:
            print("YES")
        else:
            print("NO")