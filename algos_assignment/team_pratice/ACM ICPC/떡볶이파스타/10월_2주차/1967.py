import sys
from collections import deque
n=int(sys.stdin.readline())
graph=[[] for _ in range(n+1)]

for i in range(n-1):
    a=list(map(int,sys.stdin.readline().split()))
    graph[a[0]].append([a[1], a[2]])
    graph[a[1]].append([a[0], a[2]])

k=-1
answer=-1

def bfs(x) :
    global k, answer
    ch=[0]*(n+1)
    dist=[0]*(n+1)
    ch[x]=1
    queue=deque()
    queue.append(x)
    while queue:
        y=queue.popleft()
        for i in range(len(graph[y])) :
            node=graph[y][i][0]
            if(ch[node]==0) :
                dist[node]=dist[y]+graph[y][i][1]
                ch[node]=1
                queue.append(node)

    k=dist.index(max(dist))
    answer=dist[k]
bfs(1)
bfs(k)
print(answer)
