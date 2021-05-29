#include <iostream>
#include <algorithm>
using namespace std;
int numA[1002];
int dp[1002];
int main() {
	int n, maxlen = 0, cnt;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numA[i];
	}
	for (int j = 0; j < n; j++) {
		dp[j] = 1;
		for (int k = 0; k < j; k++) {
			if (numA[j] < numA[k])
				dp[j] = max(dp[j], dp[k] + 1);
		}
		if (dp[j] > maxlen)
			maxlen = dp[j];
	}
	cout << maxlen << '\n';
}
