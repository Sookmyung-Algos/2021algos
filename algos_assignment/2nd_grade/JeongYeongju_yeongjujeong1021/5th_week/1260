#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int visit[1001];
vector<int> v[1001];
queue<int> q;

void dfs(int start) {
	visit[start] = 1;
	cout << start << " ";
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (visit[next] == 0)
			dfs(next);
	}
}

void bfs(int start) {
	visit[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visit[next] == 0) {
				visit[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m, s, x, y;
	cin >> n >> m >> s;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());

	dfs(s);
	cout << '\n';

	for (int i = 1; i <= n; i++)
		visit[i] = 0;

	bfs(s);
	cout << '\n';

	return 0;
}
