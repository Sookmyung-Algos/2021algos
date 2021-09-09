#include <iostream>
using namespace std;

char MOO(int k, int len, int n) {
	if (n <= 3) {
		if (n == 1) return 'm';
		else return 'o';
	}
	int mid = (len - (3 + k)) / 2;
	if (n > mid + (3 + k)) return MOO(k - 1, mid, n - (mid + (3 + k)));
	if (n <= mid) return MOO(k - 1, mid, n);
	if (n == mid + 1) return MOO(k, len, 1);
	if (n <= mid + (3 + k)) return MOO(k, len, 2);
}

int main() {
	int n; cin >> n;
	int i, length = 3;
	for (i = 0; length < n; i++) {
		length = 2 * length + (4 + i);
	}
	cout << MOO(i, length, n);
}
