#include <iostream>
#include <algorithm>
using namespace std;

int w[1001], v[1001];
int dp[1001][10010] = { 0, };

int main() {
	int n, k;
	cin >> k >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i] >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= w[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][k];
}
