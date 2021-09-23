import sys
from collections import deque
n=int(sys.stdin.readline().rstrip())
queue=deque()
for i in range(1,n+1):
    queue.append(i)

while len(queue)!=1:
    queue.popleft()
    hi=queue[0]
    queue.popleft()
    queue.append(hi)
print(queue.popleft())
