#include<algorithm>
#include<iostream>

using namespace std;
long long v[100000], tree[400000], n, q;

void init(int node, int left, int right) {
	if (left == right) {
		tree[node] = v[left ];
		return;
	}
	int mid = (left+right) /2;
	init(node * 2, left, mid);
	init((node * 2) + 1, mid + 1, right);
	tree[node] = tree[node * 2] + tree[(node * 2) + 1];
	return;
}

void update(int idx, int val, int node, int left, int right) {
	if (idx < left || idx > right) return; // 구간 벗어남
	if (left == right) {
		tree[node] = val;
		return;
	}
	long long mid = (left+right) >> 1;
	update(idx, val, node * 2, left, mid); // 왼쪽구간 
	update(idx, val, (node * 2) + 1, mid + 1, right); // 오른쪽구간 
	tree[node] = tree[node * 2] + tree[(node * 2) + 1];
	return;
}

long long query(int l, int r, int node, int s, int e) {
	if (l > e || r < s) return 0; // 노드의 구간과 쿼리의 구간이 겹치지 않을 때
	if (l <= s && e <= r) return tree[node]; // 노드의 구간이 쿼리의 구간에 완전히 포함될 때
	long long mid = (s + e)/2; 
	// s~mid와 mid+1~e로 쪼갬
	return query(l, r, node * 2, s, mid)+ query(l, r, (node * 2) + 1, mid + 1, e);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	init(1, 1, n);
	while (q--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		int a1 = (x > y) ? y : x; // 더 작은 값 저장
		int b1 = (x > y) ? x : y; // 더 큰 값 저장
		cout << query(a1, b1, 1, 1, n) << '\n';
		update(a, b, 1, 1, n);
	}
	return 0;
}
