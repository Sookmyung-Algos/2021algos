#include <iostream>
#include <vector>
using namespace std;
int n,k,q,m;
bool arr[5010];
bool sleep[5010];
vector<int>v;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> k >> q >> m;
	v.resize(n+3,0);
	for(int i=0;i<k;i++){
		int a;
		cin >> a;
		sleep[a] = 1;
	}
	for(int i=0;i<q;i++){
		int a;
		cin >> a;
		//if(sleep[a])continue;
		for(int j=a;j<=n+2;j+=a){
			if(sleep[j])continue;
			arr[j] = 1;//check
		}
	}
	for(int i=3;i<=n+2;i++){
		v[i] = arr[i]==0 ? v[i-1]+1 : v[i-1]+0;
	}
	for(int i=0;i<m;i++){
		int s,e;
		cin >> s >> e;
		cout << v[e]-v[s-1] << '\n';
	}
}
