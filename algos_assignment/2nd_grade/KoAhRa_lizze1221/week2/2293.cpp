#include <iostream>
#include <cstdio>
using namespace std;

int main() {

	int i, j, n, k;
	int dp[10001] = { 0, };

	cin >> n >> k;

	int coins[100];

	for (i = 0; i < n; i++) cin >> coins[i];

	dp[0] = 1;
	for (i = 0; i < n; i++) {
		for (j = coins[i]; j <= k; j++) {
			if (j - coins[i] >= 0) {
				dp[j] += dp[j - coins[i]]; 
			}
		}
	} // 합이 k가 될때까지 경우의 수 구하기

	cout << dp[k];
	return 0;
}
