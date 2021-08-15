from sys import stdin
from collections import deque
n, c= map(int, stdin.readline().split())
roll= list(map(int, stdin.readline().split()))
roll= sorted(sorted(roll, key= lambda x: x//10), key= lambda x: x%10)
roll= deque(roll)
cnt=0
while(len(roll)!=0):
    if(roll[0]==10):
        cnt+=1
        roll.popleft()
    elif(roll[0]>10):
        if(c==0):
            break
        c-=1
        cnt+=1
        roll[0]-=10
    elif(roll[0]<10):
        roll.popleft()
print(cnt)
