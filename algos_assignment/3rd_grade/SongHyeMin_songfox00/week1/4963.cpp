#include<iostream>
#include<cstring>

using namespace std;

bool visit[51][51] = { false, };
int w, h;
int map[51][51];
int dx[8] = { 1,-1,0,0,1,1,-1,-1};
int dy[8] = { 0,0,-1,1,1,-1,-1,1 };

void dfs(int a, int b) {
	visit[a][b] = true;

	for (int i = 0; i < 8; i++) {
		int nx = a + dx[i];
		int ny = b + dy[i];

		if (nx >= 0 && nx <= h && ny >= 0 && ny <= w && !visit[nx][ny] && map[nx][ny]==1) {
			visit[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	while (true) {
		int cnt = 0;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !visit[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << '\n';

		memset(visit, false, sizeof(visit));
		memset(map, 0, sizeof(map));
		cnt = 0;
	}

	return 0;
}
