#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num, grape[10001], dp[10001];
	cin >> num;

	for(int i = 1; i <= num; i++) {
		cin >> grape[i];
	}

	dp[0] = 0;
	dp[1] = grape[1];
	dp[2] = grape[1] + grape[2];

	for (int i = 3;i <= num;i++) {
		int a, b, c;
		a = dp[i - 1];
		b = dp[i - 2] + grape[i];
		c = dp[i - 3] + grape[i - 1] + grape[i];

		dp[i] = max(max(a, b), c);
	}

	cout << dp[num];

	return 0;
}
