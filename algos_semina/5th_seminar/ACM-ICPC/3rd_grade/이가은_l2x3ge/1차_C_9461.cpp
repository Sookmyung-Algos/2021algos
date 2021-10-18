#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long dp[101] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2;
	for (int i = 6;i < 101;i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		cout << dp[a] << "\n";
	}


	return 0;
}
