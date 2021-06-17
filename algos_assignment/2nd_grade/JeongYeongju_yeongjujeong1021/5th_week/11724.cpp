#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

vector<int> graph[MAX];
int visit[MAX] = { 0, };
queue<int> q;

void bfs(int start) {
	int cur, next;
	visit[start] = 1;

	q.push(start);
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			next = graph[cur][i];
			if (!visit[next]) {
				q.push(next);
				visit[next] = 1;
			}
		}
	}
}

int main() {
	int n, m, u, v, cnt = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			bfs(i);
			cnt++;
		}
	}

	cout << cnt << '\n';
}
