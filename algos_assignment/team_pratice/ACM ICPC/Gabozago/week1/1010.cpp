#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int dp[35][35] = { 0 };

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		for (int j = 1; j <= m; j++) {  //기저조건에서 n이 1인 경우만 따지고 n==m은 안 따짐
			dp[1][j] = j;
		}
		//점화식
		for (int j = 2; j <= n; j++) {
			for (int k = 2; k <= m; k++) {
				dp[j][k] = dp[j][k - 1] + dp[j - 1][k - 1];
			}
		}
		cout << dp[n][m] << "\n";
	}
}
