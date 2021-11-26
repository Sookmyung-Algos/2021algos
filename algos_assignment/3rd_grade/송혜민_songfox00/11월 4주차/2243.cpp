#include <iostream>
#define MAX 1000000

using namespace std;

long long v[1000001];
long long tree[1 << 21];

long long query(int node_idx, int s, int e, int k){
	if (s == e)
		return s;
	int mid=(s+e)/2;
	if (k <= tree[node_idx * 2])
		return query(node_idx * 2, s, mid, k);
	else
		return query(node_idx * 2 + 1, mid + 1, e, k - tree[node_idx * 2]);
}

void update(int node_idx, int node_left, int node_right, int update_idx, long long val){
	if(node_left > update_idx || node_right < update_idx)	
		return;
	if(node_left == node_right){
		tree[node_idx] += val;
		return;
}
	int mid=(node_left+node_right)/2;
	update(node_idx*2, node_left, mid, update_idx, val);
	update(node_idx*2+1, mid+1, node_right, update_idx, val);
	tree[node_idx]=tree[node_idx*2]+tree[node_idx*2+1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	long long a,b,c;
	while (n--) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			int res = query(1, 1, MAX, b);
			cout << res << '\n';
			update(1, 1, MAX, res, -1);
		}
		else {
			cin >> b >> c;
			update(1, 1, MAX, b, c);
		}
	}
	
	return 0;
}