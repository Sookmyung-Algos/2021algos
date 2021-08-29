#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int init(vector<int> &a, vector<int> &tree, int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	return tree[node] = min(init(a, tree, start, mid, node * 2),init(a, tree, mid + 1, end, node * 2 + 1));
}

void update(vector<int> &tree, int node, int start, int end, int index, int val) {
	if (index < start || index > end) return;
	if (index == start && index == end) {
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(tree, node * 2, start, mid, index, val);
	update(tree, node * 2 + 1, mid + 1, end, index, val);
	tree[node] = min(tree[node * 2],tree[node * 2 + 1]);
}

int MIN(vector<int> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 2e9;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return min(MIN(tree, node * 2, start, mid, left, right), MIN(tree, node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0), cout.tie(0);

	int n, q;
	scanf("%d", &n);
	vector<int> a(n);
	vector<int> tree(4*n);

	for (int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
	}

	init(a, tree, 0, n - 1, 1);

	scanf("%d", &q);

	while (q--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t1 == 2) {
			printf("%d\n", MIN(tree, 1, 0, n - 1, t2 - 1, t3 - 1));
		}
		else if (t1 == 1) {
			t2 -= 1;
			a[t2] = t3;
			update(tree, 1, 0, n - 1, t2, t3);
		}
	}
	return 0;
}
