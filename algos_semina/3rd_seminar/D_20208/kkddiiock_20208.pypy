from sys import stdin


def dfs(xx, yy, hp, milk):
    global answer

    for x, y in mp:
        if v[x][y] == 2:	
            dist = abs(xx - x) + abs(yy - y)
            if dist <= hp:		
                v[x][y] = 0	
                dfs(x, y, hp + h - dist, milk + 1)
                v[x][y] = 2	

    if abs(xx - hx) + abs(yy - hy) <= hp:
        answer = max(answer, milk)


n, m, h = map(int, stdin.readline().rstrip().split())
v = [list(map(int, stdin.readline().rstrip().split())) for i in range(n)]

mp = []    
hx, hy = 0, 0

for i in range(n):
    for j in range(n):
    
        if v[i][j] == 1:
            hx, hy = i, j
            
        if v[i][j] == 2:
            mp.append((i, j))

answer = 0
dfs(hx, hy, m, 0)
print(answer)
