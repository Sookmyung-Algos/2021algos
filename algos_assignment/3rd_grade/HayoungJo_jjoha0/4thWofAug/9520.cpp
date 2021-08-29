#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 987654321

using namespace std;

int N;
int adj[1501][1501];
int dp[1501][1501];

int solve(int l, int r) {

    if (l == N - 1 || r == N - 1)
        return 0;

    int &costTime = dp[l][r];

    if (costTime != -1)
			return costTime;

    costTime = INF;
    int next = max(l, r) + 1;
    return costTime = min(costTime, min(solve(next, r) + adj[next][l], solve(l, next) + adj[r][next]));

}

int main() {

    memset(dp, -1, sizeof dp);

    scanf("%d", &N);

    for (int n = 0;n < N;n++) for (int m = 0;m < N;m++) scanf("%d", &adj[n][m]);

    printf("%d\n", solve(0, 1) + adj[0][1]);

    return 0;

}
