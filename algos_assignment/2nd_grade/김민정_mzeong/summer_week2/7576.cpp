#include <iostream>
#include <queue>
using namespace std;

int m, n, num, ripe_num;
int box[1001][1001];
bool ripe[1001][1001];
queue<pair<int, int>> q;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int bfs() {
	int cnt = -1;
	if (num == 0) return 0;

	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int y = q.front().first; 
			int x = q.front().second; q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (0 > ny || ny >= n || 0 > nx || nx >= m) continue;
				if (box[ny][nx] == -1) continue;
				if (ripe[ny][nx]) continue;
				ripe[ny][nx] = true;
				q.push({ ny, nx });
				ripe_num++;
			}
		}
		cnt++;
	}
	if (ripe_num == num) return cnt;
	else return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				ripe[i][j] = true;
				q.push({ i, j });
			}
			if (box[i][j] == 0) num++; // 익혀야 할 토마토의 개수 카운트
		}
	}
	cout << bfs();
}
