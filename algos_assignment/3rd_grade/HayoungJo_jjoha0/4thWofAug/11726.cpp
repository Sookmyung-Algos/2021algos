#include <cstdio>

using namespace std;

int DP(int * dp, int n) {
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++)
            dp[i] = (dp[i-1] + dp[i-2]) % 10007;

    return dp[n];
}

int main() {

    int n;
    scanf("%d", &n);

    int dp[n+1];
    printf("%d\n", DP(dp, n));

    return 0;
}
