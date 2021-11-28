#include <iostream>

#define endl "\n"
#define MAX 1000001
using namespace std;

int p[MAX];

int find(int n) {
	if (n == p[n])
		return n;
	return p[n] = find(p[n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		p[i] = i;

	int op, a, b;
	for (int i = 0; i < m; i++) {
		cin >> op >> a >> b;

		if (op == 0) {
			a = find(a);
			b = find(b);

			if (a > b)
				p[a] = b;
			else if (a < b)
				p[b] = a;
		}
		else if (op == 1) {
			a = find(a);
			b = find(b);

			if (a == b)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}
