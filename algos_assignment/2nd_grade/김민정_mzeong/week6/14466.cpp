#include <iostream>
#include <queue>
#include <vector>
#include <string.h> // memset
using namespace std;

int N, K, R;
int arr[101][101][4];
int visit[101][101];
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> cow;

void bfs(int sr, int sc) {
	queue<pair<int, int>> q;

	visit[sr][sc] = 1;
	q.push({ sr, sc });
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second; q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr <= 0 || nr > N || nc <= 0 || nc > N) continue;
			if (visit[nr][nc]) continue;
			if (arr[r][c][i]) continue;

			visit[nr][nc] = 1;
			q.push({ nr, nc });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K >> R;
	for (int i = 0; i < R; i++) {
		int r, c, rr, cc;
		cin >> r >> c >> rr >> cc;
		for (int j = 0; j < 4; j++) {
			int nr = r + dr[j];
			int nc = c + dc[j];
			if (nr == rr && nc == cc) {
				arr[r][c][j] = 1;
				arr[rr][cc][(j + 2) % 4] = 1;
			}
		}

	}
	for (int i = 0; i < K; i++) {
		int r, c; cin >> r >> c;
		cow.push_back({ r, c });
	}

	int ans = 0;
	for (int i = 0; i < K; i++) {
		memset(visit, 0, sizeof(visit));
		bfs(cow[i].first, cow[i].second);

		for (int j = i + 1; j < K; j++) {
			if (visit[cow[j].first][cow[j].second] == 0) ans++;
		}
	}
	cout << ans;
}
