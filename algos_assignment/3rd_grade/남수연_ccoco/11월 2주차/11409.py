import sys

n = int(input())
matrix = []
dp = [[0 for _ in range(n)] for _ in range(n)]

for _ in range(n):
    matrix.append(list(map(int, sys.stdin.readline().split())))

for l in range(1, n):
    for i in range(n-l):
        j = i + l
        dp[i][j] = 2 ** 31
        for k in range(i, j):
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1])

print(dp[0][n-1])
