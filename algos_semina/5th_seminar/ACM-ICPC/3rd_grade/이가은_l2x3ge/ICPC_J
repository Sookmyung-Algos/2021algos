#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int arr[301][301];
int dp[301][301] = { 0, };
int ans = 0;

int n, m;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> arr[i][j];
		}
	}

	//누적
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + arr[i][j];
		}
	}
	//
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {

			for (int x = i;x <= i + 10 && x<=n;x++) {
				for (int y = j; y <= j + 10 && y<=m ; y++) {

					int a = dp[x][y] - dp[i - 1][y] - dp[x][j - 1] + dp[i - 1][j - 1];
					if (a == 10)
						ans++;
					else if (a > 10) {
						break;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
