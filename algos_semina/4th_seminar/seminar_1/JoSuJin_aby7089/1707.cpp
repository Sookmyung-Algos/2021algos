#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector <int> g[20001];
int visit[20001], k, v, e;

void dfs(int s, int color) {  //이분 그래프==연결된 노드의 색을 다르게
	visit[s] = color;
	for (int i = 0; i < g[s].size(); i++) {
		int next = g[s][i];
		if (!visit[next]) {  //방문x
			if (visit[s] == 1)
				dfs(next, 2);
			else if (visit[s] == 2)
				dfs(next, 1);
		}
	}
}

bool check() {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			int next = g[i][j];
			if (visit[next] == visit[i])
				return false;
		}
	}
	return true;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= v; j++) {
			g[j].clear();
			visit[j] = 0;
		}
		cin >> v >> e;
		for (int j = 0; j < e; j++) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for (int j = 1; j <= v; j++) {
			if (visit[j] == 0)
				dfs(j, 1);
		}
		if (check())
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}
