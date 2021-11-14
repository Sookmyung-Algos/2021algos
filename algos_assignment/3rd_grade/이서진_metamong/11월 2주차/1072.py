import sys
from math import floor
input=sys.stdin.readline
a,b=map(int,input().split())
e=floor(100*b/a)
low,high=0,1000000000
if e>=99:print(-1)
else:
    while low<=high:
        mid=(low+high)//2
        aa,bb=a+mid,b+mid
        if floor(100*bb/aa)>e:high=mid-1
        else: low=mid+1
    print(high+1)
