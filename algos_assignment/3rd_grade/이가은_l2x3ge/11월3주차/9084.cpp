#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int dp[10002];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		v.clear();
		cin >> n;
		for (int i = 0;i < n;i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		cin >> m;
		fill(dp, dp + m + 1, 0);
		dp[0] = 1;
		for (int i = 0;i < n;i++) {
			for (int j = v[i];j <= m;j++) {
				dp[j] += dp[j-v[i]];
			}
		}

		cout << dp[m] << "\n";
	}
}
