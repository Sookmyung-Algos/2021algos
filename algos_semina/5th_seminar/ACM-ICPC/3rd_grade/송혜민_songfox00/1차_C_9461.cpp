#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;

	long long dp[101];

	dp[1] = 1, dp[2] = 1, dp[3] = 1;
	for (int j = 0; j < t; j++) {
		cin >> n;
		if (n < 4) {
			cout << dp[n]<<'\n';
			continue;
		}
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 2] + dp[i - 3];
		}
		cout << dp[n]<<'\n';
	}
}