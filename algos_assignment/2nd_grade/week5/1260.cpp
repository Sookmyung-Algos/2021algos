#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool dvisit[1000];
bool bvisit[1000];
vector <int> v[10001];
queue <int> q;
int virus = 0;
void dfs(int start) {
	dvisit[start] = true;
	cout << start << " ";
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (dvisit[next] == false)
			dfs(next);
	}
}
void bfs(int start) {    //큐 이용
	bvisit[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (int i = 0; i < v[node].size(); i++) {
			int next = v[node][i];
			if (bvisit[next] == false) {
				bvisit[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 0; i < m; i++) {
		int u, k;
		cin >> u >> k;
		v[u].push_back(k);
		v[k].push_back(u);
	}
	for (int z = 1; z < n + 1; z++)   //정점 번호가 작은 순서대로 방문. (weight대신)
		sort(v[z].begin(), v[z].end());
	dfs(t);
	cout << "\n";
	bfs(t);
}
