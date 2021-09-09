import sys

n, m= map(int, sys.stdin.readline().rstrip().split(' '))
a= list(map(int, sys.stdin.readline().rstrip().split(' ')))

hap=[]
nam=[0]*m
result=0

for i in range(len(a)):
    if i==0:
        hap.append(a[i]%m)
        nam[hap[i]]+=1
    else:
        hap.append((hap[i-1]+ a[i])%m)
        nam[hap[i]]+=1
        
result+= nam[0]

for i in range(m):
    result+= int(nam[i]*(nam[i]-1)/2)
    
print(result)
