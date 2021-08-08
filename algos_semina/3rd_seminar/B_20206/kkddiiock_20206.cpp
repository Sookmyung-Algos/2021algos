from sys import stdin
from collections import deque

dx= [1, -1, 0, 0]
dy= [0, 0, 1, -1]

n, m= map(int, stdin.readline().rstrip().split())
camera= [list(map(int, stdin.readline().rstrip().split())) for _ in range(n)]
vaccine= [list(map(int, stdin.readline().rstrip().split())) for _ in range(n)]
mark=[]
tmp=[]
v=[]

def dfs(a, b, c, d):
    global mark
    global tmp
    if([c, d] not in mark and camera[a][b]==camera[c][d]):
        mark.append([c, d])
        tmp.append([c, d])
        for i in range(4):
            x= c+dx[i]
            y= d+dy[i]
            if(0<=x<n and 0<=y<m):
                dfs(c, d, x, y)
            
def check(n, m):
    global mark
    global tmp
    global v
    for i in range(n):
        for j in range(m):
            if([i, j] not in mark):
                dfs(i, j, i, j)
                v.append(tmp)
                tmp=[]
        
check(n, m)            
cnt=0

for i in range(len(v)):
    a, b= v[i][0][0], v[i][0][1]
    if(camera[a][b]!=vaccine[a][b]):
        cnt+=1

if(cnt==1 or cnt==0):
    print('YES')
else:
    print('NO')
