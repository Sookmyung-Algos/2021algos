#include <iostream>
using namespace std;

int arr[1005][1005];
int sum[1005][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();

	string s;
	int n, m, min_num, ans = 0, tmp;
	cin >> n >> m;
	min_num = min(n, m);

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i + 1][j + 1] = s[j] - '0';
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];

	for (int k = min_num; k > 0; k--) {
		for (int i = 0; i + k <= n; i++) {
			for (int j = 0; j + k <= m; j++) {
				tmp = sum[i + k][j + k] - sum[i + k][j] - sum[i][j + k] + sum[i][j];
				if (tmp == k * k) ans = k * k;
				if (ans) break;
			} if (ans) break;
		} if (ans) break;
	}

	cout << ans << '\n';

	return 0;
}
