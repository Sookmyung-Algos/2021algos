#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1e9+1

using namespace std;

int n, m;
vector<long long>v;
vector<long long>tree;
vector<long long>tree2;

long long init(int L, int R, int node) {  //최솟값 tree 초기화
	if (L == R)
		return tree[node] = v[L];
	int mid = (L + R) / 2;
	return tree[node] = min(init(L, mid, node * 2), init(mid + 1, R, node * 2 + 1));
}

long long init2(int L, int R, int node) { //최댓값 tree 초기화
	if (L == R)
		return tree2[node] = v[L];
	int mid = (L + R) / 2;
	return tree2[node] = max(init2(L, mid, node * 2), init2(mid + 1, R, node * 2 + 1));
}

long long query(int left, int right, int node, int start, int end) {  //최솟값
	if (left > end || right < start)
		return INF;
	if (left <= start && right >= end)
		return tree[node];
	int mid = (start + end) / 2;
	return min(query(left, right, node * 2, start, mid), query(left, right, node * 2 + 1, mid+1, end));
}

long long query2(int left, int right, int node, int start, int end) { //최댓값
	if (left > end || right < start)
		return -1;
	if (left <= start && right >= end)
		return tree2[node];
	int mid = (start + end) / 2;
	return max(query2(left, right, node * 2, start, mid), query2(left, right, node * 2 + 1, mid + 1, end));
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
	tree2.resize(n * 4);
	init(0, n-1, 1);
	init2(0, n - 1, 1);

	for (int i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
		
		cout << query(a-1, b-1, 1, 0, n-1) << ' ';
		cout << query2(a - 1, b - 1, 1, 0, n - 1) << '\n';
	}
	return 0;
}
