#include <iostream>
#include <vector>
using namespace std;
 
int n, k, q, m, x, s, e, add;
bool sleep[5005], chk[5005];
vector<int> psum;
 
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
 
	cin >> n >> k >> q >> m;
	psum.resize(n + 3, 0);
	while (k--) {
		cin >> x;
		sleep[x] = 1;
	}
	while (q--) {
		cin >> x;
		if (sleep[x]) continue;
		add = x;
		while (x <= n + 2) {
			if (sleep[x]) {
				x += add;
				continue;
			}
			chk[x] = 1, x += add;
		}
	}
	for (int i = 3; i <= n + 2; i++) psum[i] = psum[i - 1] + (chk[i] == 0);
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << psum[e] - psum[s - 1] << '\n';
	}
}
