#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, a, b;
	cin >> t;
	while (t--) {
		a = 0, b = 0;
		cin >> n;
		for (int i = 2; i <= n; i *= 2) a += n / i;
		for (int i = 5; i <= n; i *= 5) b += n / i;
		cout << min(a, b) << '\n';
	}

	return 0;
}
