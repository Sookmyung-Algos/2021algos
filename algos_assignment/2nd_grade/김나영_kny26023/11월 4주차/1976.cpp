#include <iostream>

#define endl "\n"
#define MAX 201
using namespace std;

int p[MAX];

int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}

void union_find(int a, int b) {
	a = find(a);
	b = find(b);

	p[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		p[i] = i;

	int x, y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> x;
			if (x)
				union_find(i, j);
		}
	}

	cin >> x;
	y = find(x);
	for (int i = 1; i < m; i++) {
		cin >> x;
		if (y != find(x)) {
			cout << "NO" << endl;
			exit(0);
		}
	}
	cout << "YES" << endl;
}
