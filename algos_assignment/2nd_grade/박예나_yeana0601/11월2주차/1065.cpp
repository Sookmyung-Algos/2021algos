#include <iostream>
using namespace std;

int n, tmp, side, cnt=0;
int is_han;

int han(int n) {
	int i, cnt = 0, hund, ten, one;
	if (n < 100) {
		return n;
	}
	else {
		for (i = 100; i <= n; i++) {
			hund = i / 100;
			ten = (i % 100) / 10;
			one = i % 10;
			if (hund - ten == ten - one) {
				cnt++;
			}
		}
		return cnt + 99;
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	cout << han(n);
}
