#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int visit[1001];
vector<int> v[1001];
queue<int> q;
int cnt;

void bfs(int start) {
	cnt = 0;
	visit[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cnt++;
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
	int n, m, x, y;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	bfs(1);
	cout << cnt - 1 << '\n';

	return 0;
}
