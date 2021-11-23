#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int w[21], v[21];
int dp[21][210] = { 0, };

int main() {
	cin>>k >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
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
