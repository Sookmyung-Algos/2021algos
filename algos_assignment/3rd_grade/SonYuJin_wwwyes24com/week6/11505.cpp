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
	return tree[node] = (makeTree(start, mid, node * 2) * makeTree(mid + 1, end, node * 2 + 1)) % 1000000007;
}

ll mul(ll start, ll end, ll left, ll right, ll node) {
	if (left > end || right < start) // 범위 밖
		return 1;
	if (left <= start && end <= right) // 범위 안
		return tree[node];
	ll mid = (start + end) / 2;
	return (mul(start, mid, left, right, node * 2) * mul(mid + 1, end, left, right, node * 2 + 1)) % 1000000007;
}

ll update(ll start, ll end, ll index, ll val, ll node) {
	if (index < start || index > end) // 범위 밖
		return tree[node];

	if (start == end) 
		return tree[node] = val;

	ll mid = (start + end) / 2;
	return tree[node] = (update(start, mid, index, val, node * 2) * update(mid + 1, end, index, val, node * 2 + 1)) % 1000000007;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, m, k;
	ll a, b, c;

	cin >> n >> m >> k;
	for (ll i = 1; i <= n; i++) 
		cin >> num[i];
	
	makeTree(1, n, 1);

	for (ll i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, b, c, 1);
		}
		else if (a == 2) {
			cout << mul(1, n, b, c, 1) << "\n";
		}
	}
}
