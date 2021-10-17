#include <iostream>
using namespace std;

int main() {
	while (true) {
		int n, dp[10001] = {0}; double m;
		scanf("%d%lf", &n, &m);
		if (!n && m < 0.001) break;
		pair<int,int> candy[5001];
		for (int i = 0; i < n; ++i) {
			int c; double p;
			scanf("%d%lf", &c, &p);
			candy[i] = {c, (int) (p * 100 + 0.5)};
		}
		int maximum = (int) (m * 100 + 0.5);
		for (int i = 0; i < n; ++i)
			for (int j = candy[i].second; j <= maximum; ++j)
				dp[j] = max(dp[j], dp[j - candy[i].second] + candy[i].first);
		printf("%d\n", dp[maximum]);
	}
	return 0;
}
