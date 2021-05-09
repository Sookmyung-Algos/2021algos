#queue 쓰면 시간 초과
from collections import deque

n = int(input())
deq = deque([i for i in range(1, n+1)])

while len(deq) > 1:
    deq.popleft()
    first = deq.popleft()
    deq.append(first)

print(deq[0])
