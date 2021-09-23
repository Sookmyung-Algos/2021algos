import sys
def push(x):
    stack.append(x)
def pop():
    if(not stack):
        return -1
    else : 
        return stack.pop()

def size():
    return len(stack)

def empty():
    if len(stack)==0:
        return 1
    else:
        return 0

def top():
    if len(stack)==0:
        return -1
    else:
        return stack[-1]

n=int(sys.stdin.readline().rstrip())
stack=[]

for i in range(n):
    word=sys.stdin.readline().split()
    order=word[0]
    if order=="push": 
        push(word[1])
    elif order=="pop":
        print(pop())
    elif order=="size":
        print(size())
    elif order=="top":
        print(top())
    elif order=="empty":
        print(empty())
