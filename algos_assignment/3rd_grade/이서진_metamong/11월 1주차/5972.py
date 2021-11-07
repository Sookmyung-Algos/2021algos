import sys
import heapq
MAX=sys.maxsize

def hi(start):
    queue=[]
    heapq.heappush(queue,(0, start))
    distance[start]=0
    while queue:
        d,now=heapq.heappop(queue)
        if distance[now]<d:
            continue
        for v, w in graph[now]:
            cost=d+w
            if cost<distance[v]:
                distance[v]=cost
                heapq.heappush(queue,(cost,v))

n,m = map(int, input().split())
graph = [[] for _ in range(n+1)]
distance = [MAX]*(n+1)
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))
hi(1)
print(distance[n])

