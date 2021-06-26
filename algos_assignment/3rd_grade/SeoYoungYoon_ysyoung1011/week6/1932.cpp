#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a[501][501];
	long long dp[501][501];

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	}
	dp[1][1] = a[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == 1) dp[i][j] = dp[i - 1][j] + a[i][j];
			else if (j == i) dp[i][i] = dp[i - 1][j - 1] + a[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
		}
	}
	long long m = dp[n][1];
	for (int i = 2; i <= n; i++) {
		if (dp[n][i] > m) m = dp[n][i];
	}
	cout << m;
}
