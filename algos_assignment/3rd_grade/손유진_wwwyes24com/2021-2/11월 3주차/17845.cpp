#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001][100001];
int I[1001], T[1001];

int main() {
	int k, n;
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		cin >> I[i] >> T[i];

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= T[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - T[i]] + I[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[k][n];
	return 0;
}
