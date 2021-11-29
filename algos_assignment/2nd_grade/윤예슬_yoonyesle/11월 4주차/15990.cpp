#include <iostream>
using namespace std;

#define MOD 1'000'000'009

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		long long dp[100'001][4], n;
		scanf("%lld", &n);
		dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
		dp[2][1] = 0; dp[2][2] = 1; dp[2][3] = 0;
		dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
		for (int i = 4; i <= n; ++i)
			for (int j = 1; j <= 3; ++j)
				dp[i][j] = (dp[i - j][j % 3 + 1]
					+ dp[i - j][(j + 1) % 3 + 1]) % MOD;
		printf("%lld\n", ((dp[n][1] + dp[n][2]) % MOD + dp[n][3]) % MOD);
	}
	return 0;
}
