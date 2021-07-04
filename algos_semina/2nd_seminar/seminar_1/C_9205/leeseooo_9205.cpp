#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int t, n;
vector<int>graph[102];
bool visit[102];
bool distance(pair<int,int>a,pair<int,int>b) {
	if (abs(a.first - b.first) + abs(a.second - b.second) <= 1000)
		return true;
	else return false;
}
void dfs(int node) {
	visit[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visit[next])
			dfs(next);
	}
}
int main() {
	cin >> t;
	while (t--) {
		vector<pair<int, int>>v;
		memset(visit, false, sizeof(visit));
		memset(graph, 0, sizeof(graph));
		cin >> n;
		for (int i = 0; i < n + 2; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		for (int i = 0; i < n+2; i++) {
			for (int j = i + 1; j < n + 2; j++) {
				if (distance(v[i], v[j])) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}
		dfs(0);
		if (!visit[n + 1]) {
			cout << "sad\n";
		}
		else {
			cout << "happy\n";
		}
	}
}
