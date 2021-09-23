#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
double ans;
vector <pair<double, double>> v;
vector <pair<double,pair<int, int>>> edge;
int p[110];

int findParent(int a) {     //부모 찾기
	if (p[a] == a)
		return a;
	else
		return p[a] = findParent(p[a]);
}

bool same(int a, int b) {   //부모가 같은지 판단
	a = findParent(a);
	b = findParent(b);
	if (a == b)
		return true;
	else
		return false;
}

void Union(int a, int b) {   //부모가 다른 두 노드 연결시키기
	a = findParent(a);
	b = findParent(b);
	if (a != b)
		p[b] = a;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 0; i < v.size(); i++) {
		double x1 = v[i].first;
		double y1 = v[i].second;
		for (int j = i + 1; j < v.size(); j++) {
			double x2 = v[j].first;
			double y2 = v[j].second;
			double dis = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
			edge.push_back({ dis,{ i, j }});
		}
	}

	for (int i = 0; i < n; i++)  //부모노드를 자기 자신으로 초기화
		p[i] = i;
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); i++) {  //사이클 없애기..어떻게?
		double cost = edge[i].first;
	
		if (same(edge[i].second.first, edge[i].second.second)==false){
			Union(edge[i].second.first, edge[i].second.second);
			ans += cost;
		}
	}
	cout.precision(3);
	cout << ans;
}
