#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
vector <vector<int>> vv;
bool visit[101];
int ans = 0;

void dfs(int a, int b, int count) {
	visit[a] = true;
	if (a == b)
		ans = count;
	for (int i = 0; i < vv[a].size(); i++) {
		int next = vv[a][i];
		if (visit[next] == false)
			dfs(next, b, count + 1);
	}
}

int main(){
	int n, m, parent, child;
	cin >> n >> parent >> child;
	vv.resize(n + 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		vv[u].push_back(v);
		vv[v].push_back(u);
	}
	dfs(parent, child, 0);
	if (ans == 0)
		cout << -1;
	else
		cout << ans;
}
