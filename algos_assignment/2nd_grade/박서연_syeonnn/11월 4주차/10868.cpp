// 10868 최솟값

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, k;
vector<long long> tree, arr;

int init(int node, int start, int end) {
	int mid = (start + end) / 2;
	if (start == end)
		return tree[node] = arr[start];
	else 
		return tree[node] = min(init(2 * node, start, mid),
		init(2 * node + 1, mid + 1, end));
}



int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 1000000000;
	if (left <= start && end <= right)
		return tree[node];
	return min(query(2 * node, start, (start + end) / 2, left, right)
		, query(2 * node + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	arr.resize(n);
	tree.resize(tree_size);

	for (int i = 0; i < n; i++) cin >> arr[i];

	init(1, 0, n - 1);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << query(1, 0, n - 1, a - 1, b - 1) << '\n';
	}

	return 0;
}
