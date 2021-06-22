import sys
N=int(sys.stdin.readline())
M=int(sys.stdin.readline())
matrix=[[0]*(N+1) for i in range(N+1)]
for i in range(M):
    a,b=map(int,sys.stdin.readline().split())
    matrix[a][b]=matrix[b][a]=1
check=[0]*(N+1)

V=1
ans=[]

def dfs(V):
    check[V]=1
    ans.append(0)
    for i in range(1,N+1):
        if(check[i]==0 and matrix[V][i]==1):
            dfs(i)

dfs(V)
print(len(ans)-1)
