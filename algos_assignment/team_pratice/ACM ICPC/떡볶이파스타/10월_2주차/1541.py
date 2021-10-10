import sys 

exp=sys.stdin.readline().split('-')
num=[]

for hi in exp:
    cnt=0
    plus=hi.split('+')
    for n in plus:
        cnt+=int(n)
    num.append(cnt)
answer=num[0]
for i in range(1, len(num)):
    answer-=num[i]

print(answer)
