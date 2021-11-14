#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;

int n, m;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int mp[51][51][2], dist[51][51][2];
priority_queue<pair<pair<int, int>, pair<int, int>>> pq;

pair<int, int> st, en;

void dijkstra() {
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) { dist[i][j][0] = INF; dist[i][j][1] = INF; }
	dist[st.first][st.second][0] = 0; dist[st.first][st.second][1] = 0;
	pq.push({ {0, 0}, {st.first, st.second} });

	while (!pq.empty()) {
		int tr = -pq.top().first.first;
		int ne = -pq.top().first.second;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();

		if ((tr > dist[a][b][0]) || (tr == dist[a][b][0] && ne > dist[a][b][1])) continue;

		for (int k = 0; k < 4; k++) {
			int x = a + dx[k];
			int y = b + dy[k];

			if (x < 0 || n <= x || y < 0 || m <= y) continue;

			int ntr = tr + mp[x][y][0];
			int nne = ne + mp[x][y][1];

			if (dist[x][y][0] > ntr) {
				dist[x][y][0] = ntr;
				dist[x][y][1] = nne;
				pq.push({ {-ntr, -nne}, {x, y} });
			}
			else if (dist[x][y][0] == ntr && dist[x][y][1] > nne) {
				dist[x][y][1] = nne;
				pq.push({ {-ntr, -nne}, {x, y} });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			cin >> c;
			if (c == 'S') st = { i, j };
			else if (c == 'F') en = { i, j };
			else if (c == 'g') {
				mp[i][j][0] = 1;
				mp[i][j][1] = 0;
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (0 <= x && x < n && 0 <= y && y < m && mp[x][y][0] == 0) mp[x][y][1] = 1;
				}
			}
		}
	}

	mp[st.first][st.second][0] = 0; mp[st.first][st.second][1] = 0;
	mp[en.first][en.second][0] = 0; mp[en.first][en.second][1] = 0;

	dijkstra();

	cout << dist[en.first][en.second][0] << ' ' << dist[en.first][en.second][1] << '\n';

	return 0;
}
