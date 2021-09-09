import sys
from sys import stdin
from collections import deque

n, m, x= map(int, stdin.readline().split())
higher= [[] for i in range(n+1)]
lower= [[] for i in range(n+1)]
visited= [0]*(n+1)

def bfs(x, arr):
    result=0
    q= deque()
    q.append(x)
    visited[x]=True
    while(len(q)):
        v= q.popleft()
        for vv in arr[v]:
            if not visited[vv]:
                q.append(vv)
                visited[vv]=True
                result+= 1
    return result

for i in range(m):
    a, b= map(int, stdin.readline().split())
    higher[a].append(b)
    lower[b].append(a)
    
print(1+bfs(x, lower), n-bfs(x, higher))
