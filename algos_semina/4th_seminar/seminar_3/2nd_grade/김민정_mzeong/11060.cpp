#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000
int arr[1010];
int dp[1010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	fill(dp, dp + n + 1, MAX); dp[1] = 0;
	for (int i = 1; i < n; i++) {
		int jump = arr[i];
		for (int j = 1; j <= jump; j++) {
			if (i + j <= n) dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}

	if (dp[n] == MAX) cout << -1;
	else cout << dp[n];
}
