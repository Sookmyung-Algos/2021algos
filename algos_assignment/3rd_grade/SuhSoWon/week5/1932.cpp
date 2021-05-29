#include <iostream>
#include <algorithm>
using namespace std;
int tri[501][501];
int dp[501][501];
int main() {
	int n, maxsum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	dp[0][0] = tri[0][0];
	if (n >= 2) {
		dp[1][0] = dp[0][0] + tri[1][0];
		dp[1][1] = dp[0][0] + tri[1][1];
	}
	for (int i = 2; i < n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
		}
		dp[i][0] = dp[i - 1][0] + tri[i][0];
		dp[i][i] = dp[i - 1][i - 1] + tri[i][i];
	}
	for (int k = 0; k < n; k++) {
		if (dp[n - 1][k] > maxsum)
			maxsum = dp[n - 1][k];
	}
	cout << maxsum << '\n';
}
