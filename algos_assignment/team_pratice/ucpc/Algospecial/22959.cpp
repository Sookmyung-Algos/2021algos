#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 200'001
#define INF 2147483647

long long arr[MAX], tree[MAX << 2], tr[MAX << 2];

int n;

void init(int node, int start, int end) {
	if (start == end) {
		tree[node] = tr[node] = arr[start];
		return;
	}
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	tr[node] = min(tr[node * 2], tr[node * 2 + 1]);
}

void update(int node, int start, int end, int i, long long value) {
	if (i < start || end < i) return;
	if (start == end) {
		tree[node] = tr[node] = value;
		return;
	}
	update(node * 2, start, (start + end) / 2, i, value);
	update(node * 2 + 1, (start + end) / 2 + 1, end, i, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	tr[node] = min(tr[node * 2], tr[node * 2 + 1]);
}

long long query(int node, int start, int end, int b, int c) {
	if (c < start || end < b) return 0;
	if (b <= start && end <= c) return tree[node];
	return query(node * 2, start, (start + end) / 2, b, c)
		+ query(node * 2 + 1, (start + end) / 2 + 1, end, b, c);
}

long long query2(int node, int start, int end, int b, int c) {
	if (c < start || end < b) return INF;
	if (b <= start && end <= c) return tr[node];
	return min(query2(node * 2, start, (start + end) / 2, b, c)
		, query2(node * 2 + 1, (start + end) / 2 + 1, end, b, c));
}

int bound_r(int s, int e, int value) { // value보다 작은 첫 번째 인덱스
	while (s < e) {
		int m = (s + e) / 2;
		if (query2(1, 1, n, s, m) < value) // 앞쪽에 value보다 작은게 있음
			e = m;
		else
			s = m + 1;
	}
	// 현재 s는 value보다 작다. 하지만 s == n인 경우, value 이상일 수 있다.
	if (query(1, 1, n, s, s) < value)
		return s - 1;
	return s;
}

int bound_l(int s, int e, int value) { // value보다 작은 마지막 인덱스
	while (s < e) {
		int m = (s + e) / 2;
		if (query2(1, 1, n, m + 1, e) < value) // 뒷쪽에 value보다 작은게 있음
			s = m + 1;
		else
			e = m;
	}
	if (query(1, 1, n, s, s) < value)
		return s + 1;
	return s;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", arr + i);
	init(1, 1, n);
	int m;
	scanf("%d", &m);
	while (m--) {
		int c, i, j, left, right;
		scanf("%d%d%d", &c, &i, &j);
		switch (c) {
			case 1: update(1, 1, n, i, j); break;
			case 2: if (query(1, 1, n, i, i) < j) printf("0\n");
					else {
						left = bound_l(1, i, j);
						right = bound_r(i, n, j);
						// printf("%d %d -> ", left, right);
						printf("%lld\n", query(1, 1, n, left, right));
					}
		}
	}
	return 0;
}
