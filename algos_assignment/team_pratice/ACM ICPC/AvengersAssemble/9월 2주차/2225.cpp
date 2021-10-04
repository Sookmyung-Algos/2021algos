#include<iostream>
#define MAX 1000000000

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;

	long long dp[201][201] = { 0, };

	dp[1][1] = 1;
	
	for (int i = 2; i <= 200; i++) {
		dp[1][i] = dp[1][i - 1] + 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int z = 1; z <= k; z++) {
			for (int j = 1; j <= z; j++) {
				dp[i][z] = (dp[i][z] + dp[i - 1][j] % MAX)%MAX;
			}
		}
	}

	cout << dp[n][k];
	return 0;
}
