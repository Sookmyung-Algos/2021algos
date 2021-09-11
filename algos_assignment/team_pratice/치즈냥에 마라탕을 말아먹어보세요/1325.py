from sys import stdin
from collections import deque
input= stdin.readline

n, m= map(int, input().rstrip().split())
mat= [[] for _ in range(n+1)]
for i in range(m):
    a, b= map(int, input().rstrip().split())
    mat[b].append(a)
result= []
fcnt=0

def bfs(s):
    q= deque()
    q.append(s)
    mark= [0 for _ in range(n+1)]
    mark[s]=1
    cnt=1
    while(q):
        t= q.popleft()
        for i in mat[t]:
            if(mark[i]==0):
                mark[i]=1
                cnt+=1
                q.append(i)
    return cnt

for i in range(1, n+1):
    tmp= bfs(i)
    if(fcnt==tmp):
        result.append(i)
    if(fcnt<tmp):
        fcnt=tmp
        result=[]
        result.append(i)
        
for i in range(len(result)):
    print(result[i], end=' ')
