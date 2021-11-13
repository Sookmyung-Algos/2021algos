def gcd(a, b):
    if b == 0: 
        return a
    return gcd(b, a % b)
    
def lcm(a, b):
    return a * b // gcd(a, b)
 
n, m = map(int, input().split())
item = [[0,0]] + [[*map(int, input().split())] for _ in range(n)]
bag = [0] + [int(input()) for _ in range(m)]
dp = [[0] * (max(bag)+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(max(bag) + 1):
        dp[i][j] = max(dp[i][j], dp[i-1][j])
        if j - item[i][0] >= 0:
            dp[i][j] = max(dp[i][j], dp[i-1][j-item[i][0]] + item[i][1])
 
ans = 1

for i in range(2, m+1):
    LCM = lcm(bag[ans], bag[i])
    val1 = dp[n][bag[ans]] * LCM // bag[ans]
    val2 = dp[n][bag[i]] * LCM // bag[i]
    if val2 > val1: 
        ans = i
        
print(ans)
