#include <iostream>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;

void NetworkFlow(int start, int end);
vector<int> adj[500];
int c[500][500], f[500][500];
int visit[500];

int n, m, result = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		adj[0].push_back(i);
		c[0][i] = 1;
		int a, b;
		cin >> a;
		for (int j = 0;j < a;j++) {
			cin >> b;
			adj[i].push_back(b+n);
			adj[b+n].push_back(i);
			c[i][b + n] = 1;
			adj[b+n].push_back(n+m+1);
			c[b+n][n+m+1] = 1;
		}
	}
	NetworkFlow(0, n+m+1);
	cout << result;
}

void NetworkFlow(int start, int end) {
	while (1) {
		fill(visit, visit+n+m+2, -1);
		//bfs
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int i = 0;i < adj[x].size();i++) {
				int y = adj[x][i];
				if (c[x][y] - f[x][y] > 0 && visit[y] == -1) {
					q.push(y);
					visit[y] = x;
					if (y == end) break;
				}
			}
		}
		//종결
		if (visit[end] == -1) break;

		//유량구하기
		/*
		int flow = 98754321;
		for (int i = end;i != start;i = visit[i])
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);
			*/

		for (int i = end;i != start;i = visit[i]) {
			f[visit[i]][i] += 1;
			f[i][visit[i]] -= 1;
		}
		result += 1;
	}
}
