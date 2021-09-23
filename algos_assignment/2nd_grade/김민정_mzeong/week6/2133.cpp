#include <iostream>
using namespace std;

int dp[31];
int main() {
	int n; cin >> n;

	if (n % 2 == 1) { // 홀수면 무조건 경우의 수 0
		cout << 0;
		return 0;
	}

	dp[0] = 1; 
	dp[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i - 4; j >= 0; j--) {
			dp[i] += dp[j] * 2;
		}
	}
	cout << dp[n];
}
