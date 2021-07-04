#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	long long res=0;
	long long arr[1000002] = { 0, };
	cin >> n >> k;
	long long dp[1000002];

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[b] = a;
	}
	dp[0] = arr[0];
	for (int i = 1; i <= 1000000; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}
	if (k <= 1000000) {
		for (int i = 0; i <= 1000000; i++) {
			if (i + k <= 1000000 && i - k >= 1)
				res = max(res, dp[i + k] - dp[i - k - 1]);
		}
		cout << res;
	}
	else
		cout << dp[1000000];
	return 0;
}
