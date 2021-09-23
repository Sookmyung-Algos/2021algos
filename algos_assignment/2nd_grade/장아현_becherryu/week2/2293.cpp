#include <iostream>
using namespace std;
int coins[101];
int dp[10001];

int main(void) {
	
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}

	dp[0] = 1; //동전 선택X

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coins[i])
				dp[j] += dp[j - coins[i]];
		}
	}
	cout << dp[k] << endl;
	return 0;
}
