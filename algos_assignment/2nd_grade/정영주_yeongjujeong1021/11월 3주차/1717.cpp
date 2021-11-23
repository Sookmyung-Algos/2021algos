#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int parent[1000001];

int find(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = find(parent[x]);
}

void sum(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) parent[fy] = fx;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) parent[i] = -1;

	for (int i = 0, c, a, b; i < m; i++) {
		cin >> c >> a >> b;
		if (c) {
			if (find(a) == find(b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
		else sum(a, b);
	}

	return 0;
}
