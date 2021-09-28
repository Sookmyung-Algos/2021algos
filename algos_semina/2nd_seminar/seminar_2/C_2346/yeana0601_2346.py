n = int(input())
b = list(map(int, input().split()))

copy=b
answer = []
idx = []
for i in range(n):
    idx.append(i+1)

i=0
temp=b.pop(i)
answer.append(idx.pop(i))

while b:
    if(temp<0):
        i =(i+temp)%len(b)
    else:
        i = (i+(temp-1))%len(b)
    temp = b.pop(i)
    answer.append(idx.pop(i))

for j in range(n):
    print(answer[j], end=' ')
