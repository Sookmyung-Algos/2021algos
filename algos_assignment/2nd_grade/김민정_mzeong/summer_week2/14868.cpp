#include <iostream>
#include <queue>
using namespace std;

int n, k;
int map[2001][2001];
int parent[100001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> union_q;
queue<pair<int, int>> bfs_q;

int Find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
	u = Find(u); v = Find(v);
	if (u == v) return false;

	if (u < v) parent[v] = u;
	else parent[u] = v;
	return true;
}

void union_check() {
	while (!union_q.empty()) {
		int cury = union_q.front().first;
		int curx = union_q.front().second;
		union_q.pop();
		bfs_q.push({ cury, curx });

		for (int i = 0; i < 4; i++) {
			int ny = cury + dy[i];
			int nx = curx + dx[i];
			if (ny <= 0 || n < ny || nx <= 0 || n < nx) continue;
			if (map[cury][curx] == map[ny][nx] || map[ny][nx] == 0) continue;

			if (Union(map[cury][curx], map[ny][nx])) k--;
		}
	}
}

void bfs() {
	while (!bfs_q.empty()) {
		int cury = bfs_q.front().first;
		int curx = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cury + dy[i];
			int nx = curx + dx[i];
			if (ny <= 0 || n < ny || nx <= 0 || n < nx || map[ny][nx] != 0) continue;

			map[ny][nx] = map[cury][curx];
			union_q.push({ ny, nx });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		map[y][x] = i + 1;
		union_q.push({ y, x });
	}
	for (int i = 0; i < 100001; i++) parent[i] = i;

	int cnt = 0;
	while (k > 1) {
		union_check(); // (1) 문명끼리 인접해 있는지 확인 -> 결합
		if (k == 1) break;
		bfs();// (2) 인접한 지역에 문명 전파
		cnt++;
	}
	cout << cnt;
}
