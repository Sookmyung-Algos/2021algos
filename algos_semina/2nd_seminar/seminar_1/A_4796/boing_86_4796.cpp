#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int num = 1;

	while (1) {
		int l, p, v;
		int div, re, ans;

		cin >> l >> p >> v;

		if (l==0 && p==0 && v==0) {
			break;
		}

		div = v / p;
		re = v % p;

		if (re > l) {
			ans = div * l + l;
		}

		else {
			ans = div * l + re;
		}

		cout << "Case " << num++ << ": " << ans << "\n";
	}
}
