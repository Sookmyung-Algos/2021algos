#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1e9+1

using namespace std;

int n, m;
vector<long long>v;
vector<long long>tree;

long long init(int L, int R, int node) {
	if (L == R)
		return tree[node] = v[L];
	int mid = (L + R) / 2;
	return tree[node] = min(init(L, mid, node * 2), init(mid + 1, R, node * 2 + 1));	//최솟값 반환
}

long long query(int left, int right, int node, int start, int end) {
	if (left > end || right < start)
		return INF;
	if (left <= start && right >= end)
		return tree[node];
	int mid = (start + end) / 2;
	return min(query(left, right, node * 2, start, mid), query(left, right, node * 2 + 1, mid+1, end));	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	for(int i=0;i<n;i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	tree.resize(n * 4);
	init(0, n-1, 1);
	for (int i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
		
		cout << query(a-1, b-1, 1, 0, n-1) << '\n';
	}
	return 0;
}
