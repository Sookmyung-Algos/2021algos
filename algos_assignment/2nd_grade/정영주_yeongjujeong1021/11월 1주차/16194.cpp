#include <iostream>
using namespace std;

int arr[1001];
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) dp[1][i] = arr[1] * i;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = min(dp[i - 1][j], dp[i][j - i] + arr[i]);
		}
	}

	cout << dp[n][n] << '\n';

	return 0;
}
