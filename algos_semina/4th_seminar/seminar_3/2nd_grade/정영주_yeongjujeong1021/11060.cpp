#include <iostream>
#include <cstring>
using namespace std;

int arr[1001], dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	memset(dp, -1, sizeof(dp));

	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] == -1) continue;
		for (int j = 1; j <= arr[i] && j < n; j++) {
			if (dp[i + j] == -1) dp[i + j] = dp[i] + 1;
			else dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}
