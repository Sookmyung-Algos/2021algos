#include <iostream>
#include <algorithm>
using namespace std;
long long dp[1001][11];
int main() {

	int t, n;
	cin >> t;

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k >= 0; k--)
				dp[i][j] += dp[i - 1][k];
		}
	}

	for (int i = 0; i < t; i++) {
		cin >> n;
		long long sum = 0;
		for (int j = 0; j < 10; j++)
			sum += dp[n][j];
		cout << sum << '\n';
	}
}
