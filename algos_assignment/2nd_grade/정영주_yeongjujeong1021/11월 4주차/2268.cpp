#include <iostream>
#include <cmath>
using namespace std;

long long* tree;
long long arr[1000001];

long long init(int node, int s, int e) {
	if (s == e) return tree[node] = arr[s];
	long long m = (s + e) / 2;
	return tree[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
}

void update(int node, int s, int e, int idx, long long dif) {
	if (idx < s || idx > e) return;
	tree[node] += dif;
	if (s == e) return;
	int m = (s + e) / 2;
	update(node * 2, s, m, idx, dif);
	update(node * 2 + 1, m + 1, e, idx, dif);
}

long long sum(int node, int s, int e, int l, int r) {
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) return tree[node];
	int m = (s + e) / 2;
	return sum(node * 2, s, m, l, r)
		+ sum(node * 2 + 1, m + 1, e, l, r);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int height = (int)ceil(log2(n));
	tree = new long long[1 << (height + 1)];

	init(1, 0, n - 1);

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		if (!a) {
			if (b > c) swap(b, c);
			cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
		}
		else {
			update(1, 0, n - 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
	}

	return 0;
}
