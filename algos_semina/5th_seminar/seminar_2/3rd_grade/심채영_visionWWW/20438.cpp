#include <iostream>
#include <vector>
using namespace std;

int n, k, q, m, x, s, e, add;
bool stdarr[5005], sleep[5005], chk[5005];
 
int main() {

	cin >> n >> k >> q >> m;

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
			chk[x] = 1;
      x += add;
		}
	}
	for (int i = 3; i <= n + 2; i++) stdarr[i] = stdarr[i - 1] + (chk[i] == 0);
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << stdarr[e] - stdarr[s - 1] << '\n';
	}
}
