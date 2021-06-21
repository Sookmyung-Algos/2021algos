n, m = map(int, input().split())
s = []
q = []
#큐를 만들어주기
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
#x와 y를 정해준다.
for i in range(n):
    s.append(list(input()))
    #s에 추가
q = [[0, 0]]
s[0][0] = 1
#BFS 방법
while q:
    a, b = q[0][0], q[0][1]
    del q[0]
    for i in range(4):
        x = a + dx[i]
        y = b + dy[i]
        if 0 <= x < n and 0 <= y < m and s[x][y] == "1":
            q.append([x, y])
            s[x][y] = s[a][b] + 1
print(s[n - 1][m - 1])
