#include <iostream>
using namespace std;


int main() {
	int pan[110][110];
	long long int dp[110][110];
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> pan[i][j];
			dp[i][j] = 0;
		}
	}
	
	dp[0][0] = 1; // 시작칸까지 이동하는 경로 수
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			if (a == n - 1 && b == n - 1)
				break;
			if (dp[a][b] > 0) {
				if (a + pan[a][b] < n) {
					dp[a + pan[a][b]][b] += dp[a][b];
				}
				if (b + pan[a][b] < n) {
					dp[a][b + pan[a][b]] += dp[a][b];
				}
			}
		}
	}
	cout << dp[n - 1][n - 1];
}
