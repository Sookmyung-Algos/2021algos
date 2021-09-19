n=int(input()) 
num=list(map(int, input().split())) 
stack=[]
answer=[-1]*n
for i in range(n):
    while stack and num[stack[-1]] < num[i]:
        answer[stack.pop()] = num[i] 
    stack.append(i) 
print(*answer)
