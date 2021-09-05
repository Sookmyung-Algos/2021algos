#include<iostream>
#include<vector>
#include<algorithm>
#define N_ 100000
using namespace std; 

int n, m, par[N_], ans; 
vector<pair<int, pair<int, int>>> v; 

int find(int x) {
	if (x == par[x])
		return x; 
	return par[x] = find(par[x]); 
}

bool Merge(int x, int y) {
	x = find(x); 
	y = find(y); 
	if (x == y)
		return false; 
	par[y] = x; 
	return true; 
}

int main() {
	int v1, v2, w;
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);   

	cin >> n >> m; 
	for (int i = 1; i <= n; i++)
		par[i] = i; 
	
	while (m--) {
		cin >> v1 >> v2 >> w; 
		v.push_back({ w, {v1, v2}}); 
	}
	sort(v.begin(), v.end());    // 가중치순 오름차순 정렬 
	
	for (int i = 0; i < v.size(); i++) {
		int w = v[i].first; 
		int v1 = v[i].second.first; 
		int v2 = v[i].second.second; 
		if (Merge(v1, v2))  // 사이클 발생하지 않을경우 연결   
			ans += w;    // 연결비용 더해주기 
	}
	cout << ans; 
	return 0; 
}
