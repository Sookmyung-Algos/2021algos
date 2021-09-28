#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
#include<math.h>
using namespace std;
int n;
double ans;
int parent[101];
vector<pair<double, pair<int, int>>>v;
vector<pair<double, double>>pos;
int Find(int x) {
	if (parent[x] == x)return x;
	else  return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y)parent[y] = x;
}
bool sameParent(int x,int y) {
	x = Find(x);
	y = Find(y);
	if (x == y)return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		pos.push_back({ x,y });
	}
	for (int i = 0; i < pos.size(); i++) {
		for (int j = i + 1; j < pos.size(); j++) {
			double cost;
			cost = sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2));
			v.push_back({ cost,{i,j} });
		}
	}
	sort(v.begin(), v.end()); //크루스칼 알고리즘은 간선의 가중치가 작은것부터 선택해서 연결하기 때문
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < v.size(); i++) {
		if (sameParent(v[i].second.first, v[i].second.second) == false) {
			Union(v[i].second.first, v[i].second.second);
			ans += v[i].first;
		}
	}
	cout.precision(3);
	cout << ans;
}
