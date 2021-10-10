#include <iostream>
#include <algorithm>
using namespace std;

long long  sum[110][110];
long long  ans = -1;

int main() {
	int n, m;
	cin >> n >> m;

	char str[110];
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= m; j++) {
			sum[i][j] = str[j - 1] - '0';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	for (int a = 1; a < n; a++) { //1~4
		for (int b = 1; b < m; b++) {
			ans = max(ans, sum[a][b] * (sum[n][b] - sum[a][b]) * (sum[n][m] - sum[n][b]));
			ans = max(ans, sum[n][b] * (sum[a][m] - sum[a][b]) * (sum[n][m] - sum[n][b] - sum[a][m] + sum[a][b]));
			ans = max(ans, sum[a][m] * (sum[n][b] - sum[a][b]) * (sum[n][m] - sum[n][b] - sum[a][m] + sum[a][b]));
			ans = max(ans, sum[a][b] * (sum[a][m] - sum[a][b]) * (sum[n][m] - sum[a][m]));
		}
	}
	for (int a = 1; a <= m - 2; a++) {// 5
		for (int b = a + 1; b <= m - 1; b++) {
			ans = max(ans, sum[n][a] * (sum[n][b] - sum[n][a]) * (sum[n][m] - sum[n][b]));
		}
	}
	for (int a = 1; a <= n - 2; a++) {// 6
		for (int b = a + 1; b <= n - 1; b++) {
			ans = max(ans, sum[a][m] * (sum[b][m] - sum[a][m]) * (sum[n][m] - sum[b][m]));
		}
	}

	cout << ans;
	return 0;
}
