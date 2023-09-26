def solve():
    n, c = map(int, input().split())
    a = list(map(int, input().split()))
    l = 0
    r = 1000000000
    while l <= r:
        m = (l + r) // 2
        res = 0
        for i in a:
            res += (i + 2 * m) ** 2
        if res == c:
            print(m)
            break
        if res > c:
            r = m - 1
        else:
            l = m + 1

t = int(input())
for _ in range(t):
    solve()