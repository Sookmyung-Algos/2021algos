from sys import stdin
n = int(input())
# 데이터 저장용
m = [[0]*n for _ in range(n)]
# 방문 내역 저장용
v = [[0]*n for _ in range(n)]

# matrix에 아파트 유무 0과 1 저장
for i in range(n):
    line = stdin.readline().strip()
    for j, b in enumerate(line):
        m[i][j] = int(b)

# 방향 확인용 좌표 dx와 dy
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

# DFS 함수
def dfs(x, y, c):
    v[x][y] = 1   
    # 방문 여부 표시
    global nums            
    if m[x][y] == 1:
        m[x][y] = c
        nums += 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < n:
            if v[nx][ny] == 0 and m[nx][ny] == 1:
                dfs(nx,ny, c)
                #재귀호출문

cnt = 1
numlist = []
nums=0
for a in range(n):
    for b in range(n):
        if m[a][b] == 1 and v[a][b] == 0:
            dfs(a,b,cnt)
            numlist.append(nums)
            nums = 0
            cnt += 1

print(len(numlist))
for n in sorted(numlist):
    print(n)
