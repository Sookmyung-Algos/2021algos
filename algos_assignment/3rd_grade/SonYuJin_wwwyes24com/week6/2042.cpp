#include <iostream>
#define MAX 1000000
using namespace std;
typedef long long ll;
ll num[MAX];
ll tree[4 * MAX];

ll makeTree(ll start, ll end, ll node) {
	if (start == end) // 구간이 하나만 포함할때
		return tree[node] = num[start];
	ll mid = (start + end) / 2;
	return tree[node] = makeTree(start, mid, node * 2) + makeTree(mid + 1, end, node * 2 + 1);
}

ll sum(ll start, ll end, ll left, ll right, ll node) {
	if (left > end || right < start) // 범위 밖
		return 0;
	if (left <= start && end <= right) // 범위 안
		return tree[node];
	ll mid = (start + end) / 2;
	return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
}

void update(ll start, ll end, ll index, ll val, ll node) {
	if (index < start || index > end) // 범위 밖
		return;
	tree[node] += val; // 값 갱신
	if (start == end) {  // 구간이 하나만 포함할 때 리턴
		num[start] += val;
		return;
	}
		

	ll mid = (start + end) / 2;
	update(start, mid, index, val, node * 2);
	update(mid + 1, end, index, val, node * 2 + 1);
}

int main() {
	ll n, m, k;
	ll a, b, c;

	cin >> n >> m >> k;
	for (ll i = 1; i <= n; i++)
		cin >> num[i];
	makeTree(1, n, 1); // 구간 합 트리 만들기
	
	for (ll i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			ll val = c - num[b];
			update(1, n, b, val, 1);
		}
		else if (a == 2) {
			cout << sum(1, n, b, c, 1) << "\n";
		}
	}
}
