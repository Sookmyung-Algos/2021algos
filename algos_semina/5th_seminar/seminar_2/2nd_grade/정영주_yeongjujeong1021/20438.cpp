#include <iostream>
#include <vector>
using namespace std;

int student[5001], sum[5001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k, q, m, s, e;
	cin >> n >> k >> q >> m;

	for (int i = 0, x; i < k; i++) {
		cin >> x;
		student[x] = -1;
	}

	for (int i = 0, x; i < q; i++) {
		cin >> x;
		if (student[x] == -1) continue;
		student[x] = 1;
		for (int j = 2; x * j <= n + 2; j++) {
			if (student[x * j] == -1) continue;
			student[x * j] = 1;
		}
	}

	for (int i = 3; i <= n + 2; i++) {
		sum[i] = sum[i - 1];
		if (student[i] == 0 || student[i] == -1) sum[i]++;
	}

	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << sum[e] - sum[s - 1] << '\n';
	}

	return 0;
}
