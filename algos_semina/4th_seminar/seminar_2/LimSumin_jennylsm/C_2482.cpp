#include<iostream>
using namespace std;
int dp[1001][1001] = { 0, };
int N, K;
int MOD = 1000000003;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= i / 2 + 1; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % MOD;//N번째 색을 선택하는 경우와 아닌경우
	return 0;
}
