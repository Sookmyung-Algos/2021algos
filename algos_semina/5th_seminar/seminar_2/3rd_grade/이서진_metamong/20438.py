import sys
n,k,q,m=map(int,sys.stdin.readline().split())
sleep=[0 for _ in range(n+3)]
chk=[0 for _ in range(n+3)]
psum=[0 for _ in range(n+3)]
for _ in range(k):
    t=int(sys.stdin.readline())
    sleep[t]=1
x=list(map(int,sys.stdin.readline().split())) 
for i in x:
    if sleep[i]==1 :
        continue
    hi=i
    while i<=n+2:
        if sleep[i]==1:
            i+=hi
            continue
        chk[i]=1
        i+=hi

for i in range(3,n+3):
    psum[i]=psum[i-1]+(chk[i]==0)
for i in range(0,m):
    s,e=map(int,sys.stdin.readline().split())
    print(psum[e]-psum[s-1])
    print()
