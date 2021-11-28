#include <iostream>
using namespace std;

long long v[1000001];
long long tree[1<<21];

void init(int node_idx, int node_left, int node_right){
	if(node_left==node_right){
		tree[node_idx]=v[node_left];
		return;
	}
	int mid=(node_left+node_right)/2;
	init(node_idx*2, node_left, mid);
	init(node_idx*2+1, mid+1, node_right);
	tree[node_idx]=tree[node_idx*2]+tree[node_idx*2+1];
}

long long query(int node_idx, int s, int e, int l, int r){
	if(s > r || e < l)
		return 0;
	if(l <= s && e <= r)
		return tree[node_idx];
	int mid=(s+e)/2;
	return query(node_idx*2, s, mid, l, r) +
		  query(node_idx*2+1, mid+1, e, l, r);
}

void update(int node_idx, int node_left, int node_right, int update_idx, long long val){
	if(node_left > update_idx || node_right < update_idx)
		return;
	if(node_left == node_right){
		tree[node_idx]=val;
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

	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	init(1,1,n);
	
	long long a, b, c;
	for(int i=0;i<m+k;i++){
		cin>>a>>b>>c;
		
		if(a==1){
			update(1,1,n,b,c);
		}
		else {
			cout<<query(1,1,n,b,c)<<'\n';
		}
	}
	
	return 0;
}