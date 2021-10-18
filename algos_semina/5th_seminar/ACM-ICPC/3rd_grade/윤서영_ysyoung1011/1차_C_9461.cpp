#include <iostream>
using namespace std;

int main() {
	int t;
	long long dp[101];
	dp[0] = 0;  dp[1] = 1; dp[2] = 1; 
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 3; i <= n; i++)
			dp[i] = dp[i - 3] + dp[i - 2];
		cout << dp[n] << endl;
	}
}
