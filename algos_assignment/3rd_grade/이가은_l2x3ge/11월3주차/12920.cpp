#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int dp[2345][12345] = { 0, };//idx, remaining Weight dp는 Value
vector<int> W;
vector<int> V;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	W.push_back(0);V.push_back(0);
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = 0;c > 0;j++) {
			int tmp = min(1 << j, c);
			W.push_back(a*tmp);
			V.push_back(b*tmp);
			c -= tmp;
		}
	}
	for (int i = 1;i < W.size();i++) {
		for (int j = 1;j <= M;j++) {
			if (j >= W[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[W.size()-1][M];
	return 0;
}
