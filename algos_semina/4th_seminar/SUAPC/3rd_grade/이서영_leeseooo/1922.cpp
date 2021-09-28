#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int n, m, ans;
int parent[100001];
vector<pair<int, pair<int, int>>>v;
int Find(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y)parent[y] = x;
}
bool sameParent(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y)return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v.push_back({ cost,{from,to} });
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		if (sameParent(v[i].second.first, v[i].second.second) == false) {
			Union(v[i].second.first, v[i].second.second);
			ans += v[i].first;
		}
	}
	cout << ans;
}
