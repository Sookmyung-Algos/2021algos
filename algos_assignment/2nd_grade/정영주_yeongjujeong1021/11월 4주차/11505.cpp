#include <iostream>
#include <cmath>
using namespace std;

long long* tree;
long long arr[1000001];

long long init(int node, int s, int e) {
	if (s == e) return tree[node] = arr[s];
	long long m = (s + e) / 2;
	return tree[node] = init(node * 2, s, m) * init(node * 2 + 1, m + 1, e) % 1000000007;
}

long long update(int node, int s, int e, int idx, long long dif) {
	if (idx < s || idx > e) return tree[node];
	if (s == e) return tree[node] = dif;
	int m = (s + e) / 2;
	return tree[node] = (update(node * 2, s, m, idx, dif) * update(node * 2 + 1, m + 1, e, idx, dif)) % 1000000007;
}

long long sum(int node, int s, int e, int l, int r) {
	if (l > e || r < s) return 1;
	if (l <= s && e <= r) return tree[node];
	int m = (s + e) / 2;
	return (sum(node * 2, s, m, l, r)
		* sum(node * 2 + 1, m + 1, e, l, r)) % 1000000007;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	int height = (int)ceil(log2(n));
	tree = new long long[1 << (height + 1)];

	for (int i = 0; i < n; i++) cin >> arr[i];

	init(1, 0, n - 1);

	for (int i = 0, a, b, c; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, n - 1, b - 1, c);
		else {
			if (b > c) swap(b, c);
			cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
		}
	}

	return 0;
}
