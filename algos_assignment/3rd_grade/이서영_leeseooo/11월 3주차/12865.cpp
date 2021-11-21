#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, k;
int dp[101][100001];
int w[101];
int v[101];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= w[i]) {//물건이 j보다 가벼울때
				//가방에 넣을수도 있고 안 넣을 수도 있다
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
				//i번째 선택안하는 경우 vs i번째 선택하는 경우
			}
			else {
				dp[i][j] = dp[i - 1][j];//j보다 무거우면 못넣으므로
				//i번째 선택 안하는 경우가 된다
			}
		}
	}
	cout << dp[n][k];
}
