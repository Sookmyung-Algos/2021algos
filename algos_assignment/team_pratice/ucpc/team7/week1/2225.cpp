#include <iostream>
#include <algorithm>
using namespace std;
int main() {

	int N, K, mod = 1000000000;
	cin >> N >> K;

	//dp[k][n] = k개 더해서 n나오는 경우의 수
	long dp[201][201] = { 0 };
	for (int n = 0; n <= N; n++) {
		dp[1][n] = 1;
	}

	//dp[i][j] = dp[i-1][j-0] + dp[i-1][j-1] + ... + dp[i-1][j-j] 오른쪽에서 왼쪽으로 넘기기
	for (int k = 2; k <= K; k++) {// 더하는 정수 개수
		for (int n = 0; n <= N; n++) {
			for (int l = 0; l <= n; l++) {
				dp[k][n] += dp[k - 1][l];// l은 0부터 N까지 가능(n과 같음) 
			}
			dp[k][n] %= mod;
		}
	}

	cout << dp[K][N] << endl;

	return 0;
}
