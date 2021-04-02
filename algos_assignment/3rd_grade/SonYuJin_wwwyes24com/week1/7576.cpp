#include <iostream>
#include <queue>
using namespace std;

int m, n;
int tom[1001][1001];
int t[1001][1001];
int mv_x[4] = { -1,1,0,0 }; // 상하좌우 x,y 이동값
int mv_y[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;
void bfs();

int main() {
	bool ripe = 1;
	int day = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tom[i][j];
			if (tom[i][j] == 1)  // 익은 토마토이면
				q.push({ i,j });
		}
	}
	bfs();
	for (int i = 0; i < n; i++) { // 안 익은 토마토가 있는지 확인
		for (int j = 0; j < m; j++) {
			if (tom[i][j] == 0) {
				ripe = 0;
				break;
			}
			if (day < t[i][j])
				day = t[i][j];
		}
	}
	if (ripe == 0)
		cout << -1;
	else
		cout << day;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) { // 상하좌우 토마토 탐색
			int nextX = x + mv_x[i];
			int nextY = y + mv_y[i];

			if (tom[nextX][nextY] == 0 && nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) { // 범위 내 && 안 익은 토마토이면
				tom[nextX][nextY] = 1;
				q.push({ nextX,nextY });
				t[nextX][nextY] = t[x][y] + 1;
			}
		}
	}
}
