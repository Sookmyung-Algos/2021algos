from collections import deque
import sys
from sys import stdin

input = stdin.readline

def bfs(g):
    q = deque()
    check = [0 for _ in range(n)]
    q.append(g[0])
    check[g[0]] = 1
    cnt, ans = 1, 0
    while q:
        x = q.popleft()
        ans += people[x]
        for xx in a[x]:
            if xx in g and not check[xx]:
                check[xx] = 1
                cnt += 1
                q.append(xx)
    if cnt == len(g):
        return ans
    else:
        return 0

def dfs(cnt, x, end):
    global min_ans
    if cnt == end:
        g1, g2 = deque(), deque()
        for i in range(n):
            if c[i]:
                g1.append(i)
            else:
                g2.append(i)
        ans1 = bfs(g1)
        if not ans1:
            return
        ans2 = bfs(g2)
        if not ans2:
            return
        min_ans = min(min_ans, abs(ans2 - ans1))
        return
    for i in range(x, n):
        if c[i]:
            continue
        c[i] = 1
        dfs(cnt+1, i, end)
        c[i] = 0

n = int(input())
people = list(map(int, input().split()))

a = [[] for _ in range(n)]
for i in range(n):
    x = list(map(int, input().split()))
    for j in range(1, x[0]+1):
        a[i].append(x[j]-1)

min_ans = sys.maxsize
for i in range(1, n // 2 + 1):
    c = [0 for _ in range(n)]
    dfs(0, 0, i)

if min_ans == sys.maxsize:
    print(-1)
else:
    print(min_ans)
