#include<cstdio>
#include<vector>
#include<cmath>
#define  MIN(a, b) (((a) < (b)) ? (a) : (b))
#define  MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

long long initmin(vector<long long> &a, vector<long long> &tree, int start, int end, int node) {
	if (start == end) return tree[node] = a[start];

	int mid = (start + end) / 2;
	long long aa = initmin(a, tree, start, mid, node * 2);
	long long bb = initmin(a, tree, mid + 1, end, node * 2 + 1);
	return tree[node] = MIN(aa, bb);
}

long long initmax(vector<long long> &a, vector<long long> &tree, int start, int end, int node) {
	if (start == end) return tree[node] = a[start];

	int mid = (start + end) / 2;
	long long aa = initmax(a, tree, start, mid, node * 2);
	long long bb = initmax(a, tree, mid + 1, end, node * 2 + 1);
	return tree[node] = MAX(aa, bb);
}

//left right 변하지 않는 구하고자 하는 범위
long long min(vector<long long> &tree, int start, int end, int left, int right, int node) {
	if (right < start || end < left) return 1000000000;
	if (left <= start && end <= right) return tree[node];
	
	int mid = (start + end) / 2;
	long long aa = min(tree, start, mid, left, right, node * 2);
	long long bb = min(tree, mid + 1, end, left, right, node * 2 + 1);
	return MIN(aa, bb);
}

//left right 변하지 않는 구하고자 하는 범위
long long max(vector<long long> &tree, int start, int end, int left, int right, int node) {
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	long long aa = max(tree, start, mid, left, right, node * 2);
	long long bb = max(tree, mid + 1, end, left, right, node * 2 + 1);
	return MAX(aa, bb);
}

int main() {
	int n, m;
	scanf("%d %d",&n,&m);
	vector<long long> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = 1 << (h + 1);
	vector<long long> min_tree(tree_size);
	vector<long long> max_tree(tree_size);
	for (int i = 0;i < n;i++) {
		scanf("%lld", &a[i]);
	}
	initmin(a, min_tree, 0, n - 1, 1);
	initmax(a, max_tree, 0, n - 1, 1);
	for (int i = 0;i < m;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld %lld\n", min(min_tree,1,n,a,b,1), max(max_tree, 1, n, a, b,1));
	}
	return 0;
}
