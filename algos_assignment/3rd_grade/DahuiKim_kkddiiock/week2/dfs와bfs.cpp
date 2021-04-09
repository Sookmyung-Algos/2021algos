#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

bool visit[1001];
vector<int> a[1001];
void dfs(int s) {
	visit[s] = true;
	printf("%d ", s);
	for (int i = 0; i < a[s].size(); i++) {
		int next = a[s][i];
		if (visit[next] == false) {
			dfs(next);
		}
	}
}
void bfs(int s) {
	queue<int> q;
	visit[s] = true;
	q.push(s);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		printf("%d ", node);
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (visit[next] == false) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	int n, m, start;
	scanf("%d %d %d", &n, &m, &start);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(start);
	printf("\n");
	memset(visit, false, sizeof(visit));
	bfs(start);
	printf("\n");
	return 0;
}
