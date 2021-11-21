#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
float tmp;
int dp[100002] = { 0, };
int W[5002], V[5002];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (1) {
		cin >> N >> tmp;
		K = int(tmp * 100 +0.5);
		if (N == 0 && tmp == 0.00)
			return 0;

		fill(dp, dp + K+1, 0);
		for (int i = 1;i <= N;i++) {
			cin >> W[i] >> tmp;
			V[i] = int(tmp * 100 + 0.5);
		}

		for (int i = 1;i <= N;i++) {
			for (int j = V[i];j <= K;j++) {
				dp[j] = max(dp[j], dp[j - V[i]] + W[i]);
			}
		}

		cout << dp[K] << "\n";
	}
	
	return 0;
}
