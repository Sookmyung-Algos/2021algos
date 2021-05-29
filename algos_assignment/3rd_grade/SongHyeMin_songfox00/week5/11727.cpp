#include<iostream>
#define MAX 10007;

using namespace std;

int main() {
	int n;
	cin >> n;

	int dp[1001];
	dp[1] = 1, dp[2] = 3, dp[3] = 5;

	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MAX;
	}

	cout << dp[n];
	return 0;
}
