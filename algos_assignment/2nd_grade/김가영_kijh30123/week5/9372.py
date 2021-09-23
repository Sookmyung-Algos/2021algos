import sys
T=int(sys.stdin.readline())
Fcase=[]
Ncase=[]
for i in range(T):
    N,M=map(int,sys.stdin.readline().split())
    Ncase.append(N)
    for j in range (M):
        a,b=map(int,sys.stdin.readline().split())
        Fcase.append(a)
        Fcase.append(b)

for r in range(len(Ncase)):
    print(Ncase[r]-1)
