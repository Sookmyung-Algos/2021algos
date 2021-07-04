#include <iostream>
#include <algorithm>

using namespace std;
int a[20001];
int b[20001];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int ans = 0;
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		sort(a, a + n, cmp);
		sort(b, b + m, cmp);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] > b[j]) {
					ans += (m - j);
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
