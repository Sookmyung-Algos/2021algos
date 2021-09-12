#include <iostream>
using namespace std;

long long dp[1001][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	for (int i = 1; i <= n; i++) dp[i][0] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 1; j < 10; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;

	long long sum = 0;
	for (int i = 0; i < 10; i++) sum = (sum + dp[n][i]) % 10007;
	
	cout << sum << '\n';

	return 0;
}
