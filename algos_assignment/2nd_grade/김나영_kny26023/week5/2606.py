from sys import stdin
read = stdin.readline
v={}
#배열을 하나 만들어준다.
for i in range(int(read())):
    v[i+1] = set()
for j in range(int(read())):
    a, b = map(int,read().split())
    v[a].add(b)
    v[b].add(a)
    #v에 넣어주기
    
def dfs(start, dic):
    for i in v[start]:
        if i not in visited:
            visited.append(i)
            dfs(i, v)
            #DFS 재귀호출문식
            
visited = []
dfs(1, v)
print(len(visited)-1)
