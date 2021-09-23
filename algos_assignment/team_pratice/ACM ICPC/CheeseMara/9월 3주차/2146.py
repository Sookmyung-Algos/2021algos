from sys import stdin
from collections import deque

input = stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs1(i, j):
    global cnt
    q = deque()
    q.append([i, j])
    mark[i][j] = True
    b[i][j] = cnt
    while q:
        x, y = q.popleft()
        for k in range(4):
            xx = x + dx[k]
            yy = y + dy[k]
            if 0 <= xx < n and 0 <= yy < n and b[xx][yy] == 1 and not mark[xx][yy]:
                mark[xx][yy] = True
                b[xx][yy] = cnt
                q.append([xx, yy])

def bfs2(z):
    global answer
    dist = [[-1] * n for _ in range(n)]
    q = deque()
    for i in range(n):
        for j in range(n):
            if b[i][j] == z:
                q.append([i, j])
                dist[i][j] = 0
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if b[nx][ny] > 0 and b[nx][ny] != z:
                answer = min(answer, dist[x][y])
                return
            if b[nx][ny] == 0 and dist[nx][ny] == -1:
                dist[nx][ny] = dist[x][y] + 1
                q.append([nx, ny])

n = int(input())
b = [list(map(int, input().split())) for _ in range(n)]
mark = [[False] * n for _ in range(n)]
cnt = 1
answer = 99999

for i in range(n):
    for j in range(n):
        if not mark[i][j] and b[i][j] == 1:
            bfs1(i, j)
            cnt += 1

for i in range(1, cnt):
    bfs2(i)

print(answer)
