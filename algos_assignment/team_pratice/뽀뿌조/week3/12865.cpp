#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[110][100010]; // value

int main() {
	int n, k;
	vector<pair<int,int>> bpk;

	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			bpk.push_back({ 0,0 });
			continue;
		}
		int w, v;
		cin >> w >> v;
		bpk.push_back({ w,v });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (bpk[i].first > j) // 물건의 무게가 배낭용량보다 크면
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - bpk[i].first] + bpk[i].second);
		}
	}
	
	cout << dp[n][k];
}
