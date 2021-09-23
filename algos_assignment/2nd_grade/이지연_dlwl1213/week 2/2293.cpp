#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, k;
int coin_price[101];
int dp[10001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int ans = 0, sum = 0;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> coin_price[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = coin_price[i]; j <= k; ++j) {
			dp[j] = dp[j] + dp[j - coin_price[i]];
		}
	}
	cout << dp[k];
}
