import sys
def push(x):
    stack.append(x)
def pop():
    if len(stack)==0:
        return -1
    else:
        return stack.pop()
n=int(sys.stdin.readline().rstrip())
sum=0
stack=[]
for i in range(n):
    num=int(sys.stdin.readline())
    if num==0:
        pop()
    else:
        push(num)
for i in stack :
    sum+=i
print(sum)
