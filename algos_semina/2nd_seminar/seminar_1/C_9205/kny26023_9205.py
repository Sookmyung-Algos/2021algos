from collections import deque
import sys
input = sys.stdin.readline

def bfs(x, y):
    que= deque([[x, y, 20]])
    prev= deque([[x, y, 20]])
    while que:
        x, y, beer = que.popleft()
        if x == x1 and y == y1:
            print("happy")
            return
        for i, j in d:
            if [i, j, 20] not in prev:
                far = abs(i - x) + abs(j - y)
                if beer*50 >= far:
                    que.append([i, j, 20])
                    prev.append([i, j, 20])
    print("sad")
    return

tc = int(input())

for i in range(tc):
    n = int(input())
    x0, y0 = map(int, input().split())
    d = []
    for j in range(n):
        x, y = map(int, input().split())
        d.append([x, y])
    x1, y1 = map(int, input().split())
    d.append([x1, y1])
    bfs(x0, y0)
