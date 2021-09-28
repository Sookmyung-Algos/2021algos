n=int(input().strip())
chicken=list(map(int,input().strip().split()))
k=int(input().strip())
hi=[]
for i in range(0,n,n//k):
    hi+=sorted(chicken[i:i+n//k])
print(" ".join(str(i) for i in hi))
