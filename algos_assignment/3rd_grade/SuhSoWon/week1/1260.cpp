#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int check[1002];
vector<int> line[1001];
queue<int> q;
void dfs(int x) {
	check[x] = 1;
	cout << x << ' ';

	for (int i = 0; i < line[x].size(); i++) {
		int next = line[x].at(i);
		if (check[next] == 0)
			dfs(next);
	}
}
void bfs(int x) {
	check[x] = 1;
	q.push(x);

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		cout << num << ' ';
		for (int i = 0; i < line[num].size(); i++) {
			int next = line[num].at(i);
			if (check[next] == 0) {
				check[next] = 1;
				q.push(next);
			}
		}
	}
}
int main() {
	int n, m, v, a, b;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		line[a].push_back(b);
		line[b].push_back(a);
	}
	for (int z = 1; z < n+1; z++) {
		sort(line[z].begin(), line[z].end());
	}
	dfs(v);
	cout << '\n';
	for (int k = 1; k < n+1; k++) {
		check[k] = 0;
	}
	bfs(v);
	cout << '\n';
}
