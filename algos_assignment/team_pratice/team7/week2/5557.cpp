#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long dp[101][21];
int a[101];
int main() {
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	dp[1][a[1]] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j - a[i] >= 0) {
				dp[i][j] += dp[i - 1][j - a[i]];
			}
			if (j + a[i] <= 20) {
				dp[i][j] += dp[i - 1][j + a[i]];
			}
		}
	}
	cout << dp[n - 1][a[n]] << '\n';
}
