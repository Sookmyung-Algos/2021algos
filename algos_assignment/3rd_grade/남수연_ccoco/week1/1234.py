N, R, G, B = map(int, input().split())
# dp: 레벨 n에서 장난감이 각각 r, g, b개가 남아있을 때의 경우의 수
dp = [[[[0 for _ in range(101)] for _ in range(101)] for _ in range(101)] for _ in range(N+1)]


def comb(n, k, r):
    ret = 1
    for i in range(1, n+1):
        ret *= i
    for i in range(r):
        for j in range(1, k+1):
            ret //= j
    return ret


def solve(n, r, g, b):
    if r < 0 or g < 0 or b < 0:
        return 0
    if n <= 0:
        return 1
    if dp[n][r][g][b] != 0:
        return dp[n][r][g][b]

    # 1가지 색만 사용하는 경우
    dp[n][r][g][b] += solve(n - 1, r - n, g, b)
    dp[n][r][g][b] += solve(n - 1, r, g - n, b)
    dp[n][r][g][b] += solve(n - 1, r, g, b - n)

    if n % 2 == 0:
        num = n // 2
        c = comb(n, num, 2)

        dp[n][r][g][b] += c * solve(n - 1, r - num, g - num, b)
        dp[n][r][g][b] += c * solve(n - 1, r, g - num, b - num)
        dp[n][r][g][b] += c * solve(n - 1, r - num, g, b - num)

    if n % 3 == 0:
        num = n // 3
        c = comb(n, num, 3)

        dp[n][r][g][b] += c * solve(n - 1, r - num, g - num, b - num)

    return dp[n][r][g][b]


print(solve(N, R, G, B))
