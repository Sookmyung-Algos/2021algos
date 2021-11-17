import sys
input=sys.stdin.readline
n,m=map(int,input().split())
a=[list(map(str,input()))for _ in range(n)]
answer=0
for i in range(n):
    for j in range(m):
        for k in range(m if n>m else n):
            if i+k<n and j+k<m:
                if a[i][j]==a[i+k][j]==a[i][j+k]==a[i+k][j+k]:
                    answer=max(answer,(k+1)*(k+1))
print(answer)          
