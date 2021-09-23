#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int e, s, m, a = 1, b = 1, c = 1, cnt = 1;
	cin >> e >> s >> m;

	while (1) {
		if (a == e && b == s && c == m) break;
		a = a % 15 + 1;
		b = b % 28 + 1;
		c = c % 19 + 1;
		cnt++;
	}

	cout << cnt << '\n';
	
	return 0;
}
