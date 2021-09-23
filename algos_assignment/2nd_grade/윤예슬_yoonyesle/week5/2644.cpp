#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, start, end;
	bool edge[101][101] = {false}, visited[101] = {false};
	cin >> n >> start >> end >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		edge[x][y] = true; edge[y][x] = true;
	}
	queue<pair<int, int>> q;
	q.push({start, 0});
	visited[start] = true;
	while (!q.empty()) {
		int current = q.front().first, cnt = q.front().second;
		q.pop();
		if (current == end) {
			cout << cnt; return 0;
		}
		for (int i = 1; i <= n; ++i) {
			if (!visited[i] && edge[current][i]) {
				q.push({i, cnt + 1});
				visited[i] = true;
			}
		}
	}
	cout << "-1";
	return 0;
}
