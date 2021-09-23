import sys
from collections import deque
input=sys.stdin.readline
n=int(input())
tree=[[]for i in range(n+1)]
chk=[False for i in range(n+1)]
parent=[0 for i in range(n+1)]
for i in range(n-1):
    a,b=map(int,input().split())
    tree[a].append(b)
    tree[b].append(a)

q=deque([1])
chk[1]=True

while q:
    now=q.popleft()
    for next in tree[now]:
        if not chk[next]:
            parent[next]=now;
            chk[next]=True
            q.append(next)
for i in range(2,n+1):
    print(parent[i])
