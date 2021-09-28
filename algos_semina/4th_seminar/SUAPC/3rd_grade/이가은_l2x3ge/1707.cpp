#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int color[20001];
vector<int> a[20001];

bool dfs(int node, int num) {
	color[node] = num;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (color[next] == 0) {
			if (dfs(next, 3 - num) == false) {
				return false;
			}
		}
		else if (color[next] == color[node]) {
			return false;
		}
	}
	return true;
}

int main() {
	int K, V, E;
	cin >> K;
	for (int i = 0;i < K;i++) {
		cin >> V >> E;
		//정리
		for (int i = 1; i <= V; i++) {
			a[i].clear();
			color[i] = 0;
		}
		for (int j = 0;j < E;j++) {
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		bool ok = true;
		for (int i = 1; i <= V; i++) {
			if (color[i] == 0) {
				if (dfs(i, 1) == false) {
					ok = false;
				}
			}
		}
		
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	
	}

	return 0;
}


