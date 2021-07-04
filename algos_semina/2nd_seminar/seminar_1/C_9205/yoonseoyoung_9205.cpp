#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

bool visited[103];
vector <int> g[103];

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < g[x].size(); i++) {
		int next = g[x][i];
		if (!visited[next]) dfs(next);
	}
}

int dist(pair<int, int>a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> v;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 103; i++)g[i].clear();
		for (int i = 0; i < n+2; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}

		for (int i = 0; i < n + 2; i++) {
			for (int j = i+1; j < n + 2; j++) {
				int len = dist(v[i], v[j]);
				if (len <= 1000) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		dfs(0);
		if (visited[n + 1]) cout << "happy\n";
		else cout << "sad\n";
	}
	return 0;
}
