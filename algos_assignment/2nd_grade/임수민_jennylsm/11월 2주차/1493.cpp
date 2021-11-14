#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int cnt[20];

void sol(int x, int y, int z) {
	bool ret = 1;
	int mn = min({ x, y, z }), sz = -1;
	if (!mn) return;
	for (int i = 19; i >= 0; i--) {
		if (cnt[i] && (1 << i) <= mn) {
			sz = i;
			break;
		}
	}
	if (sz == -1) {
		cout << -1 << '\n';
		exit(0);
	}
	cnt[sz]--;
	sz = 1 << sz;
	sol(x - sz, y, z);
	sol(sz, y - sz, z);
	sol(sz, sz, z - sz);
}

int main() {
	fastio;
	int x, y, z; cin >> x >> y >> z;
	int n, sum = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		cnt[a] += b;
		sum += b;
	}
	sol(x, y, z);
	cout << sum - accumulate(cnt, cnt + 20, 0) << '\n';
}
