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
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		c[a][b] = 1;
	}
	NetworkFlow(1, 2);
	cout << result;
}

void NetworkFlow(int start, int end) {
	while (1) {
		fill(visit, visit+n+1, -1);

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
