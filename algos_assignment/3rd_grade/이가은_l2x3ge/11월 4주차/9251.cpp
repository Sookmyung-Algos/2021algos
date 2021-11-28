#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	int dp[1002][1002] = { 0, };
	cin >> a >> b;

	for (int i = 1;i <= a.length();i++) {
		for (int j = 1;j <= b.length();j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	cout << dp[a.length()][b.length()];
	return 0;
}
