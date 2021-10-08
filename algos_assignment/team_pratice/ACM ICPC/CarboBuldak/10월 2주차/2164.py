import collections

n = int(input())
dq = collections.deque([x for x in range(1, n + 1)])

for i in range(n - 1):
    dq.popleft()
    dq.rotate(-1)

print(dq[0])
