#include <iostream>
#include <algorithm>
using namespace std;

int w[101], v[101];
int dp[101][10010] = { 0, };

int main() {
	int n, t;
	cin >> n >> t;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			if (j >= w[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][t];
}
