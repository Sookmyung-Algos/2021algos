#include <iostream>
#include <cmath> // pow
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, r, c;
	cin >> n >> r >> c;

	int ans = 0;
	int size = pow(2, n);
	while (size > 1) {
		size = size / 2;
		if (r >= size && c >= size) ans += size * size * 3; // 제4사분면
		else if (r >= size && c < size) ans += size * size * 2; // 제3사분면
		else if (r < size && c >= size) ans += size * size * 1; // 제2사분면
		else ans += size * size * 0; // 제1사분면
		r = r % size;
		c = c % size;
	}
	cout << ans;
}
