// 14466.cpp (G4)

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, cnt = 0;
int visit[101][101];

int v[101][101][101][101];
vector<pair<int, int>> c;
queue<pair<int, int>> q;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int i, int j) {
	memset(visit, 0, sizeof(visit));

	q.push({ i, j });
	visit[i][j] = 1;

	int x, y, a, b;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			a = x + dx[k];
			b = y + dy[k];
			if (0 < a && a <= n && 0 < b && b <= n
				&& !v[x][y][a][b] && !visit[a][b]) {
				q.push({ a, b });
				visit[a][b] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k, r;
	cin >> n >> k >> r;

	int idx = 1;
	for (int i = 0, a, b, c, d; i < r; i++) {
		cin >> a >> b >> c >> d;
		v[a][b][c][d] = 1;
		v[c][d][a][b] = 1;
	}

	for (int i = 0, a, b; i < k; i++) {
		cin >> a >> b;
		c.push_back({ a, b });
	}

	for (int i = 0; i < k; i++) {
		bfs(c[i].first, c[i].second);
		for (int j = i + 1; j < k; j++)
			if (!visit[c[j].first][c[j].second]) cnt++;
	}

	cout << cnt << '\n';
	
	return 0;
}
