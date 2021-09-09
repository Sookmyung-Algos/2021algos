#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
long long init(vector<long long> &a, vector<long long> &tree, int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	return tree[node] = init(a, tree, start, mid, node * 2) + init(a, tree, mid + 1, end, node * 2 + 1);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long val) {
	//범위 밖에 있는 경우
	if (index < start || index > end) return;
	if (index == start && index == end) {
		tree[node] = val;
		return;
	}
	//범위 안에 있으면 내려가면서 갱신
	int mid = (start + end) / 2;
	update(tree, node * 2, start, mid, index, val);
	update(tree, node * 2 + 1, mid + 1, end, index, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	vector<long long> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = 1 << (h + 1);
	vector<long long> tree(tree_size);


	init(a, tree, 0, n - 1, 1);

	while (q--) {
		int t1;
		scanf("%d", &t1);
		if (t1 == 0) {
			int t2, t3;
			scanf("%d %d", &t2, &t3);
			if (t2 > t3)
				printf("%lld\n", sum(tree, 1, 0, n - 1, t3 - 1, t2 - 1));
			else
				printf("%lld\n", sum(tree, 1, 0, n - 1, t2 - 1, t3 - 1));
		}
		else if (t1 == 1) {
			int t2;
			long long t3;
			scanf("%d %lld", &t2, &t3);
			t2 -= 1;
			a[t2] = t3;
			update(tree, 1, 0, n - 1, t2, t3);
		}
	}
	return 0;
}
