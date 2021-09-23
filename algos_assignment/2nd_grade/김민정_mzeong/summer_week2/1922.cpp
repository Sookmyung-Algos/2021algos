#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];
int height[1001];
struct edge {
	int u, v;
	int c;

	bool operator<(edge rhs) {
		return c < rhs.c;
	}
};
vector<edge> Edge;

int Find(int u) {
	if (parent[u] == -1) return u;
	return Find(parent[u]);
}

bool Union(int u, int v) {
	u = Find(u); v = Find(v);
	if (u == v) return false;

	if (height[u] < height[v]) swap(u, v);
	parent[v] = u;

	if (height[u] == height[v]) height[u]++;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		Edge.push_back({ a, b, c });
	}
	sort(Edge.begin(), Edge.end());
	fill(parent, parent + n, -1);

	int ans = 0;
	for (auto e : Edge) {
		int u = e.u, v = e.v, c = e.c;
		if (Union(u, v)) ans += c;
	}
	cout << ans;
}
