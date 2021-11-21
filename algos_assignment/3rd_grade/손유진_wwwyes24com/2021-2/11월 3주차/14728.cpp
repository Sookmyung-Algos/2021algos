#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101][10001];
int K[101], S[101];

int main() {
	int n, t;
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> K[i] >> S[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			if (j >= K[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - K[i]] + S[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][t];
	return 0;
}
