#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, k;
vector<long long>v;
vector<long long>tree;

long long init(int L, int R, int node) {  
	if (L == R)
		return tree[node] = v[L];
	int mid = (L + R) / 2;
	return tree[node] = init(L, mid, node * 2) + init(mid + 1, R, node * 2 + 1);
}

long long query(int left, int right, int node, int start, int end) {  //left, right 구간 합 구하기
	if (left > end || right < start)
		return 0;
	if (left <= start && right >= end)
		return tree[node];
	int mid = (start + end) / 2;
	return query(left, right, node * 2, start, mid) + query(left, right, node * 2 + 1, mid+1, end);
}

void update(int left, int right, int node, int idx, long long num) { //구간 트리 갱신
	if (left > idx || idx > right)
		return;
	if (left == right) {  //트리 리프인 경우
		tree[node] = num;
		return;
	}
	int mid = (left + right) / 2;
	update(left, mid, node * 2, idx, num);
	update(mid + 1, right, node * 2 + 1, idx, num);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m >> k;
	for(int i=0;i<n;i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	tree.resize(n * 4); //크기 재할당
	init(0, n - 1, 1);
	for (int i = 0; i < m + k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			update(0, n - 1, 1, b - 1, c);
		else
			cout << query(b - 1, c - 1, 1, 0, n - 1) << '\n';
	}
	return 0;
}
