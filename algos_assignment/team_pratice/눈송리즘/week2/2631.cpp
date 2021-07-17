#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[201], arr[201];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int k = 1; k <= n; k++) {
		dp[k] = 1;
		for (int i = 0; i < k; i++) {
			if (arr[i] < arr[k]) {
				dp[k] = max(dp[k], dp[i] + 1);
			}
		}
	}
	int ans = dp[1];
	for (int i = 2; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << n - ans;
}
