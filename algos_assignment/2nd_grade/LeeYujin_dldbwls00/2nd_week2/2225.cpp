//복습
#include <iostream>
using namespace std;
int n, k, dp[201][201]; //dp[k][n]
int main() {
	cin >> n >> k;
	for (int i = 0; i <= n; i++) { //전 세대 미리 만들어놓기
		dp[1][i] = 1; //1개로 1만들기
		dp[2][i] = i + 1; //2개로 i만들기
	}
	for (int i = 3; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int r = 0; r <= j; r++)	dp[i][j] = (dp[i][j] + dp[i - 1][j - r]) % 1000000000;
		}
	}
	cout << dp[k][n];
	return 0;
}
