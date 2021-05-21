import sys
from collections import deque
def bfs(sx, sy):
    queue=deque()
    visited=[]
    for i in range(601): visited.append([0]*601)
    visited[sx][sy]=1;
    queue.append([sx, sy])
    cnt=0
    while queue:
        x, y = queue.popleft()
        if(cam[x][y]=='P'): cnt+=1
        for dx, dy in d:
            nx=x+dx; ny=y+dy
            if(nx>=0 and nx<n and ny>=0 and ny<m):
                if(cam[nx][ny]!='X' and visited[nx][ny]==0):
                    visited[nx][ny]=1
                    queue.append([nx, ny])
    return cnt


n, m = map(int, sys.stdin.readline().split());
cam = []
d = [(1, 0), (0, 1), (-1, 0), (0, -1)]
for i in range(n):
    cam.append(list(sys.stdin.readline().strip()))
    if 'I' in cam[i]:
        sy = cam[i].index('I'); sx=i
cnt = bfs(sx, sy)
if(cnt>0): print(cnt)
else: print("TT")
