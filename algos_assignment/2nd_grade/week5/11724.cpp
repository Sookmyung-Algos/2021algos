#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool dvisit[1000];
vector <int> v[10001];
void dfs(int start) {
	dvisit[start] = true;
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (dvisit[next] == false)
			dfs(next);
	}
}

int main() {
	int count = 0;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, k;
		cin >> u >> k;
		v[u].push_back(k);
		v[k].push_back(u);
	}
	for (int j = 1; j < n+1; j++) {
		if (dvisit[j] == 0) {
			dfs(j);
			count++;
		}
	}
	cout << count;
}
