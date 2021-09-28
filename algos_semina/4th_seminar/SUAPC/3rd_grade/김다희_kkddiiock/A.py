from sys import stdin
from collections import deque
input= stdin.readline

n, k= map(int, input().rstrip().split())
v= list(map(int, input().rstrip().split()))

v.sort()
result=k
maxV=0
for i in range(n-1):
    a= v[0]*(i+1)
    b=v[i+1]*(n-i-1)
    if(a+b>maxV):
        maxV=a+b
result=k//maxV
if(k%maxV!=0):
    result+=1
print(int(result))
