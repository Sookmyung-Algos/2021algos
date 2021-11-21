#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
int dp[1002][10002] = { 0, };//idx, remaining Weight dp는 Value
int W[1002], V[1002];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> K >> N;
	for (int i = 1;i <= N;i++) {
		cin >> V[i] >> W[i];
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= K;j++) {
			if (j >= W[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];
	return 0;
}
