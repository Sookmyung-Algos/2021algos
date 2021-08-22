#include <iostream>
#include <algorithm>
using namespace std;

int candy[30001];
int parent[30001], person[30001];
int dp[3001];

int Find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
	u = Find(u); v = Find(v);
	if (u < v) parent[v] = u;
	else parent[u] = v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> candy[i];
		parent[i] = i;
		person[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		Union(a, b);
	}
	for (int i = 1; i <= n; i++) {
		if (parent[i] != i) {
			int p = Find(i);
			candy[p] += candy[i];
			person[p] += person[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (parent[i] != i) continue;
		for (int j = k - 1; j - person[i] >= 0; j--) {
			dp[j] = max(dp[j], dp[j - person[i]] + candy[i]);
		}
	}
	cout << dp[k - 1];
}
