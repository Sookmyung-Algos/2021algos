#include <iostream>
using namespace std;

int cnt[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, d;
	cin >> n >> d;

	for (int i = 1; i <= n; i++) {
		int tmp = i;
		while (tmp) {
			cnt[tmp % 10]++;
			tmp /= 10;
		}
	}

	cout << cnt[d] << '\n';

	return 0;
}
