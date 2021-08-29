import sys
from collections import deque
def bfs(i,j,visit) :
    que = deque([[i,j]])
    m_que = deque()
    visit[i][j] = 1
    while que :
        i,j = que.popleft()
        m_cnt = 0
        for d_x, d_y in direction :
            next_x = i + d_x
            next_y = j + d_y
            if 0 <= next_x <= n-1 and 0 <= next_y <= m-1 and visit[next_x][next_y] == 0:
                if ice[next_x][next_y] != 0:
                    visit[next_x][next_y] = 1 
                    que.append([next_x,next_y])
                else :
                    m_cnt += 1
        if m_cnt :
            m_que.append([i,j,m_cnt])
    return m_que

input=sys.stdin.readline
year = 0
n, m = map(int,input().split())
ice = []

for k in range(n):
    ice.append(list(map(int, input().split())))

direction = ((1,0),(-1,0),(0,-1),(0,1)) 

while True :
    cnt = 0 
    visit = [[0 for _ in range(m)] for _ in range(n)]
    for i in range(n-1) :
        for j in range(m-1) :
            if ice[i][j] != 0 and visit[i][j] == 0 :
                cnt += 1
                melt = bfs(i,j,visit)
                while melt :
                    m_x, m_y, melting = melt.popleft()
                    ice[m_x][m_y] = max(ice[m_x][m_y]- melting, 0)
    if cnt == 0 :
        year = 0
        break
    if cnt >= 2 :
        break
    year += 1
print(year)
