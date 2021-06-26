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
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q;
	int x, y, a, b;

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	makeTree(1, n, 1);

	while (q--) {
		cin >> x >> y >> a >> b;
		if (x > y)
			cout << sum(1, n, y, x, 1) << "\n";
		else
			cout << sum(1, n, x, y, 1) << "\n";
		ll val = b - num[a];
		update(1, n, a, val, 1);
	}
}
