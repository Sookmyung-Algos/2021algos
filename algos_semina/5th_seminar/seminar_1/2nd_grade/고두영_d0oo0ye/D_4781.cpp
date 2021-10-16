#include <bits/stdc++.h>

using namespace std;

int n;
float m, p;
int c;

vector<pair<int, int>> candy;
int dp[10001];

int main() {
	while (1) {
		cin >> n >> m;
        
		if (n == 0 && m == 0.00) break;
		candy.resize(n+1);
		int targetm = (int)m * 100;
		memset(dp, 0, sizeof(dp));
        
		for (int i = 1; i <= n; i++) {
			cin >> c >> p;
			candy[i] = { c, p * 100 };
		}
        
		for (int i = 1; i <= n; i++) {
			for (int j = candy[i].second; j <= targetm; j++) {
				dp[j] = max(dp[j], dp[j - candy[i].second] + candy[i].first);
			}
		}
		cout << dp[targetm] << "\n";
	}
	return 0;
}
