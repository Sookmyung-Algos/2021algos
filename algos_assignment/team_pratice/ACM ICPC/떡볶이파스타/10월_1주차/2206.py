import sys

dx=[1,-1,0,0]
dy=[0,0,1,-1]

def bfs():
    queue=[]
    queue.append([0,0,1])
    visit=[[[0]*2 for _ in range(m)] for __ in range (n)]
    visit[0][0][1]=1
    while queue:
        x,y,w=queue.pop(0)
        if x==n-1 and y==m-1:
            return visit[x][y][w]
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if nx>=0 and nx<n and ny>=0 and ny<m:
                if now[nx][ny]==1 and w==1:
                    visit[nx][ny][0]=visit[x][y][1]+1
                    queue.append([nx,ny,0])
                elif now[nx][ny]==0 and visit[nx][ny][w]==0:
                    visit[nx][ny][w]=visit[x][y][w]+1
                    queue.append([nx,ny,w])
    return -1

n,m=map(int,sys.stdin.readline().split())
now=[list(map(int,sys.stdin.readline().rstrip()))for _ in range(n)]
print(bfs())
