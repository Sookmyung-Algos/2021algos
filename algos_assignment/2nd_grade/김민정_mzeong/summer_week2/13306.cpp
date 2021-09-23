#include <iostream>
#include <stack>
using namespace std;

int p[200001];
int parent[200001], level[200001];
int query[400001][3];

int Find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
	u = Find(u); v = Find(v);
	if (u == v) return;

	if (level[u] < level[v]) swap(u, v);
	parent[v] = u;

	if (level[u] == level[v]) level[u]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, q; cin >> n >> q;
	p[1] = 1;
	for (int i = 1; i <= n - 1; i++) {
		int a; cin >> a;
		p[i + 1] = a;
	}
	for (int i = 0; i <= n; i++) parent[i] = i;
	for (int i = 0; i < n - 1 + q; i++) {
		int x; cin >> x;
		if (x) cin >> query[i][1] >> query[i][2];
		else {
			cin >> query[i][1]; query[i][2] = 0;
		}
	}

	stack<bool> st;
	for (int i = (n - 1 + q) - 1; i >= 0; i--) {
		if (query[i][2]) { // (2)
			if (Find(query[i][1]) == Find(query[i][2])) st.push(true);
			else st.push(false);
		}
		else Union(query[i][1], p[query[i][1]]);
	}

	while (!st.empty()) {
		cout << (st.top() ? "YES" : "NO") << "\n";
		st.pop();
	}
}
