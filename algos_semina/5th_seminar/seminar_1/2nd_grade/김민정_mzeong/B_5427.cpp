#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
int MAP[1000][1000], fireMAP[1000][1000];
queue<pair<int, int>> fire;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void escapeBuilding(int sy, int sx) {
	queue<pair<int, int>> q;

	int time = 0;

	MAP[sy][sx] = time;
	q.push({ sy, sx });
	while (!q.empty()) {
		int fsz = fire.size();
		for (int i = 0; i < fsz; i++) {
			int fy = fire.front().first;
			int fx = fire.front().second; fire.pop();
			for (int j = 0; j < 4; j++) {
				int nfy = fy + dy[j];
				int nfx = fx + dx[j];
				if (nfy < 0 || nfx < 0 || nfy >= h || nfx >= w) continue;
				if (MAP[nfy][nfx] == 0 && !(nfy == sy && nfx == sx)) continue; // 벽에는 불이 붙지X
				if (fireMAP[nfy][nfx]) continue;
				fireMAP[nfy][nfx] = 1;
				fire.push({ nfy, nfx });
			}
		}

		time++;
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			int y = q.front().first;
			int x = q.front().second; q.pop();

			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny < 0 || nx < 0 || ny >= h || nx >= w) { // 빌딩 탈출
					cout << time << "\n";
					return;
				}
				if (MAP[ny][nx] >= 0) continue; // 벽이거나 방문o
				if (fireMAP[ny][nx]) continue; // 불이 옮겨진 칸 또는 이제 붙으려는 칸
				MAP[ny][nx] = time;
				q.push({ ny, nx });
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		memset(MAP, -1, sizeof(MAP));
		memset(fireMAP, 0, sizeof(MAP));
		int sy, sx;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char input; cin >> input;
				if (input == '#') MAP[i][j] = 0;
				else if (input == '@') { sy = i, sx = j; }
				else if (input == '*') {
					fireMAP[i][j] = 1;
					fire.push({ i, j });
				}
			}
		}
		escapeBuilding(sy, sx);
		while (!fire.empty()) fire.pop();
	}
}
