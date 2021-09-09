from collections import deque
from sys import stdin

def bfs(i, j):
    q= deque()
    q.append([i, j])
    temp= []
    temp.append([i, j])
    while (q):
        x, y= q.popleft()
        for i in range(4):
            nx= x + dx[i]
            ny= y + dy[i]
            if(0<=nx<n and 0<=ny<n and mark[nx][ny]==0):
                if(l<=abs(s[nx][ny]-s[x][y])<=r):
                    mark[nx][ny]= 1
                    q.append([nx, ny])
                    temp.append([nx, ny])
    return temp
    
dx= [1, -1, 0, 0]
dy= [0, 0, -1, 1]
n, l, r= map(int, stdin.readline().split())
s= []

for i in range(n):
    s.append(list(map(int, stdin.readline().split())))
    
result = 0

while True:
    mark= [[0] * n for i in range(n)]
    t= False
    for i in range(n):
        for j in range(n):
            if(mark[i][j]== 0):
                mark[i][j]= 1
                temp= bfs(i, j)
                if(len(temp)>1):
                    t= True
                    people= sum([s[x][y] for x, y in temp])//len(temp)
                    for x, y in temp:
                        s[x][y]= people
    if not t:
        break
    result += 1
    
print(result)
