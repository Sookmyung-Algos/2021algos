#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
long long init(vector<long long> &a, vector<long long> &tree, int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	return tree[node] = init(a, tree, start, mid, node * 2) + init(a, tree, mid + 1, end, node * 2 + 1);
}

//index는 수정하고자 하는 노드
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

//left right구간합을 구하고자 하는 범위
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
	//범위 밖에 있는 경우
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

	for (int i = 0;i < n;i++) {
		scanf("%lld", &a[i]);
	}

	init(a, tree, 0, n - 1, 1);

	while (q--) {
		int t1, t2, t3;
		long long t4;
		scanf("%d %d", &t1, &t2);
		if(t1>t2)
			printf("%lld\n", sum(tree, 1, 0, n - 1, t2 - 1, t1 - 1));
		else
			printf("%lld\n", sum(tree, 1, 0, n - 1, t1-1, t2 - 1));

		scanf("%d %lld", &t3, &t4);
		t3 -= 1;
		a[t3] = t4;
		update(tree, 1, 0, n - 1, t3, t4);
		
	}
	return 0;
}
