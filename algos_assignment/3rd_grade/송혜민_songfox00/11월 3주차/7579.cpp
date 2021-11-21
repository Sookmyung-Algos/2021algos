#include<iostream>
#include<algorithm>

using namespace std;

int a[101], c[101];
int dp[101][10001];

int main() {
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		sum += c[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j - c[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + a[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= sum; i++) {
		if (dp[n][i] >= m) {
			cout << i;
			break;
		}
	}
}