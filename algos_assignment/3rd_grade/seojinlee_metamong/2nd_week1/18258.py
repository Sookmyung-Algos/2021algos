import sys
from collections import deque

queue=deque()
def push(x):
    queue.append(x)
def pop():
    if(not queue):
        return -1
    else :
        return queue.popleft()
def size():
    return len(queue)
def empty():
    if(not queue):
        return 1
    else :
        return 0
def front():
    if(not queue): return -1
    else:
        return queue[0]
def back():
    if(not queue): return -1
    else:
        return queue[-1]

n=int(sys.stdin.readline().rstrip())
for i in range(n):
    word=sys.stdin.readline().split()
    order=word[0]
    if order=="push":
        push(word[1])
    elif order=="pop":
        print(pop())
    elif order=="size":
        print(size())
    elif order=="empty":
        print(empty())
    elif order=="front":
        print(front())
    elif order=="back":
        print(back())
    
