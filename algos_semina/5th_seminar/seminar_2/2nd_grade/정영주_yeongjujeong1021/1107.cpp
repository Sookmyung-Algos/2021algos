#include <iostream>
#include <cstdlib>
using namespace std;

int num[10]; // 0 ~ 9. 1이면 고장난거

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m, x, ans, tmp, len;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		num[x] = 1;
	}
	
	ans = abs(100 - n);
	for (int i = 0; i <= 1000000; i++) {
		tmp = i;
		len = 0;
		if (tmp == 0) {
			if (num[0]) continue;
			else len = 1;
		}
		else {
			while (tmp > 0) {
				if (num[tmp % 10]) break;
				tmp /= 10;
				len++;
			}
		}
		if (tmp == 0) ans = min(ans, abs(i - n) + len);
	}

	cout << ans << '\n';

	return 0;
}
