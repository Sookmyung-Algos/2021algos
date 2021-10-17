#include <iostream>
using namespace std;
long long dp[101];
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		dp[1] = dp[2] = dp[3] = 1;
		for (int i = 4; i <= n; i++) dp[i] = dp[i - 2] + dp[i - 3];
		cout << dp[n] << "\n";
	}
}
