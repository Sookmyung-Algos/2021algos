from collections import deque
from sys import stdin

input = stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def bfs():
    while q:
        x, y = q.popleft()
        if mark[x][y] != "FIRE":
            flag = mark[x][y]
        else:
            flag = "FIRE"

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < h and 0 <= ny < w:
                if mark[nx][ny] == -1 and (
                    m[nx][ny] == "." or m[nx][ny] == "@"
                ):
                    if flag == "FIRE":
                        mark[nx][ny] = flag
                    else:
                        mark[nx][ny] = flag + 1
                    q.append((nx, ny))
            else:
                if flag != "FIRE":
                    return flag + 1

    return "IMPOSSIBLE"

n = int(input())
for _ in range(n):
    w, h = map(int, input().split())
    q = deque()
    m = []
    mark = [[-1] * w for _ in range(h)]
    for i in range(h):
        m.append(list(input().strip()))
        for j in range(w):
            if m[i][j] == "@":
                mark[i][j] = 0
                start = (i, j)
            elif m[i][j] == "*":
                mark[i][j] = "FIRE"
                q.append((i, j))
    q.append(start)
    print(bfs())
