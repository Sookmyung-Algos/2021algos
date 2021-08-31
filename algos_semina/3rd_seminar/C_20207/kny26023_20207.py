from sys import stdin

n= int(stdin.readline().rstrip())
c= [0]*367

for i in range(n):
    s, e= map(int, stdin.readline().rstrip().split())
    c[s]+=1
    c[e+1]-=1    
   
h=0
w=0
result=0

for i in range(1, 367):
    c[i]+= c[i-1]
    if(c[i]==0):
        result+= w*h
        h=0
        w=0
    else:
        h= max(h, c[i])
        w+=1
        
print(result)
