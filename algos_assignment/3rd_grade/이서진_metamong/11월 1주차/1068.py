n=int(input())
stack=list(map(int,input().split(" ")))
edge=[[-1] for _ in range(n)]
k=int(input())
root=[]
for i in range(0,n):
    if stack[i] >= 0 and i != k:
        edge[stack[i]].append(i)
    elif stack[i] == -1 and i != k:
        root.append(i)
edge[k]=[-1]
answer=0

visited = [0]*n
while root:
    n = root.pop()
    if visited[n] == 0:
        visited[n] = 1
        if len(edge[n]) == 1:
            answer+=1
        else:
            sub_node=edge[n]
            sub_node.pop(0)
            for i in sub_node:
                root.append(i)
print(answer)
