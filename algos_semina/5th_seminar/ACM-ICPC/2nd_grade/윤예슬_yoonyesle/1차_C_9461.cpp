#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		long long dp[101];
		dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 2;
		for (int i = 6; i <= n; ++i)
			dp[i] = dp[i - 1] + dp[i - 5];
		printf("%lld\n", dp[n]);
	}
	return 0;
}
