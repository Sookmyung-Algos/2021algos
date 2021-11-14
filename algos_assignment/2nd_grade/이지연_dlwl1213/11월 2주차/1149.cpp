#include <cstdio>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main() {

    int N, i, j;

    int arr[1000][3];
    int dp[1000][3];
    
    scanf("%d", &N);

    for (i = 0; i < N; i++)
        for (j = 0; j < 3; j++) scanf("%d", &arr[i][j]);
    
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for (i = 1; i < N; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }

    int ans = __INT_MAX__;
    for (i = 0; i < 3; i++) {
        if (dp[N-1][i] < ans) ans = dp[N-1][i];
    }

    printf("%d\n", ans);
    
    return 0;
}
