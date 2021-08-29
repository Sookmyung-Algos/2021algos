from sys import stdin
from collections import deque
input= stdin.readline

def bfs(y, x):
    graph[y][x] = 0
    queue = deque()
    queue.append((y, x))
    d = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    cnt = 1
    while queue:
        y, x = queue.popleft()
        for dy, dx in d:
            yy, xx = y+dy, x+dx
            if (0 <= yy < n) and (0 <= xx < m) and graph[yy][xx] == 1:
                queue.append((yy, xx))
                graph[yy][xx] = 0
                cnt += 1
    return cnt

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for i in range(n)]
result = []
for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            result.append(bfs(i, j))
print(len(result))
print(max(result) if result else 0)
