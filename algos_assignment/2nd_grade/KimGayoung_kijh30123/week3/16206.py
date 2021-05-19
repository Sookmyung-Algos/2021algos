import sys
N,Max=map(int,sys.stdin.readline().split())
EX=[]
Num=[]
O=[int(x) for x in input().split()]
count=0
Answer=[]

for i in range(N):          
    if O[i]%10==0:
        EX.append(O[i])
    else:
        Num.append(O[i])
        
EX.sort()
Num.sort()
        
for i in range(len(EX)):
    if count==Max:
        break
    
    if EX[i]==10:
        Answer.append(10)
    else:
        now=EX[i]
        while True:
            now=now-10
            Answer.append(10)
            count=count+1
            if now==10:
                Answer.append(10)
                break
            if count==Max:
                break
        
for i in range(len(Num)):
    if count==Max:
        break
    
    if Num[i]<10:
        continue

    else:
        now=Num[i]
        while now>10:
            if count==Max:
                break
            now=now-10
            Answer.append(10)
            count=count+1
            

print(len(Answer))
