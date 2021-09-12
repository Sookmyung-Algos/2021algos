#include<iostream>
#include<algorithm>

using namespace std;

int dp[501][501];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;
		int arr[501], sum[501]={0, };

		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];	//1~i까지 합
		}
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j + i <= k; j++) {
				dp[j][i+j] = 1e9;

				for (int z = j; z < i+j; z++) {
					dp[j][i+j] = min(dp[j][i+j], dp[j][z] + dp[z + 1][i+j] + sum[i+j] - sum[j - 1]);
				}
			}
		}
		cout << dp[1][k] << '\n';
	}

	return 0;
}
