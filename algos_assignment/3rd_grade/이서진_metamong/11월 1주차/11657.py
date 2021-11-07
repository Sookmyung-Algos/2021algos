import sys
import collections
input=sys.stdin.readline
MAX=sys.maxsize
def bell(start):
    distance[start]=0
    for i in range(n): 
        for j in range(m): 
            node=edges[j][0] 
            next_node=edges[j][1] 
            cost=edges[j][2]
            if distance[node]!=MAX and distance[next_node]>distance[node] + cost:
                distance[next_node]=distance[node] + cost
                if i==n-1: 
                    return True
    return False

n, m=map(int, input().split())
edges=[] 
distance=[MAX]*(n+1)
for _ in range(m):
    a,b,c=map(int, input().split()) 
    edges.append((a, b, c))
hi=bell(1)
if hi:
    print('-1')
else:
    for i in range(2, n+1):
        if distance[i] == MAX:
            print('-1')
        else: 
            print(distance[i])
