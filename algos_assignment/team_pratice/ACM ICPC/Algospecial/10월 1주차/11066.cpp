#include <iostream>
using namespace std;

#define INF 50000000

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int k;
		scanf("%d", &k);
		int size[501];
		for (int i = 0; i < k; ++i)
			scanf("%d", &size[i]);
		int dp[501][501];
		for (int i = 0; i < k; ++i)
			dp[i][i] = 0;
		int sum[501]; sum[0] = size[0];
		for (int i = 1; i < k; ++i)	sum[i] = sum[i - 1] + size[i];
		for (int d = 1; d < k; ++d) {
			for (int j = 0; j + d < k; ++j) {
				dp[j][j + d] = INF;
				for (int mid = j; mid < j + d; ++mid)
					dp[j][j + d] = min(dp[j][j + d], dp[j][mid] + dp[mid + 1][j + d]);
				if (j) dp[j][j + d] += sum[j + d] - sum[j - 1];
				else dp[j][j + d] += sum[j + d];
			}
		}
		printf("%d\n", dp[0][k - 1]);
	}
	return 0;
}
