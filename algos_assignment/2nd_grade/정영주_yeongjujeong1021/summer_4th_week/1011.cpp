#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, x, y, n;
	cin >> t;

	while (t--) {
		cin >> x >> y;
		n = y - x;
		int max = (int)sqrt(n);

		int cnt = 1;
		n -= max;

		for (int i = max - 1; i >= 1; i--) {
			n -= i * 2;
			cnt += 2;
		}

		for (int i = max; n != 0; i--) {
			cnt += n / i;
			n %= i;
		}

		cout << cnt << '\n';
	}

	return 0;
}
