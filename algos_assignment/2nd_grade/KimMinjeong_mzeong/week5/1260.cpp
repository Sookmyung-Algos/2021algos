#include <iostream>
#include <queue>
using namespace std;

int n, m, v;
int map[1001][1001] = {0,};
bool mark[1001] = {false,};
queue<int> q;

void reset() {
	for (int i = 1; i <= n; i++)
		mark[i] = false;
}

void dfs(int x) {
	mark[x] = true;
	cout << x << " ";

	for (int i = 1; i <= n; i++) {
		if (!mark[i] && map[x][i])
			dfs(i);
	}
}

void bfs(int x) {
	mark[x] = true;
	q.push(x);
	cout << x << " ";

	while (!q.empty()) {
		x = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (!mark[i] && map[x][i]) {
				mark[i] = true;
				q.push(i);
				cout << i << " ";
			}
		}
	}
}

int main() {
	int node1, node2;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		map[node1][node2] = 1;
		map[node2][node1] = 1;
	}

	dfs(v);
	cout << "\n";
	reset();
	bfs(v);
}
