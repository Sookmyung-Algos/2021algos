#include<iostream>
#define MAX 1000000007;

using namespace std;

long long dp[1000001][2] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;

	dp[0][0] = 0, dp[1][0] = 2, dp[2][0] = 7, dp[2][1] = 1;	

	for (int i = 3; i <= n; i++) {
		dp[i][1] = (dp[i - 1][1] + dp[i - 3][0]) % MAX;
		dp[i][0] = (3 * dp[i - 2][0] + 2 * dp[i - 1][0] + 2 * dp[i][1]) % MAX;
	}

	cout << dp[n][0] << '\n';
	return 0;
}
