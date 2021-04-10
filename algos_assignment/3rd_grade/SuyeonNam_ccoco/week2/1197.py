from collections import defaultdict
from heapq import *

v, e = map(int, input().split())
edges = []

for i in range(e):
    a, b, w = input().split()
    w = int(w)
    edges.append((w, a, b))


def prim(start_node, edges):
    dis = 0
    adj_edges =defaultdict(list)
    for w, a, b in edges:
        adj_edges[a].append((w, a, b))
        adj_edges[b].append((w, b, a))

    connected_nodes = set(start_node)
    candidate_edge_list = adj_edges[start_node]
    heapify(candidate_edge_list)

    while candidate_edge_list:
        w, a, b = heappop(candidate_edge_list)
        if b not in connected_nodes:
            connected_nodes.add(b)
            dis += w
        for e in adj_edges[b]:
            if e[2] not in connected_nodes:
                heappush(candidate_edge_list, e)
    return dis


print(prim('1', edges))
