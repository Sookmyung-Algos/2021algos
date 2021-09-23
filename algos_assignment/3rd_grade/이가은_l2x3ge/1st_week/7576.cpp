#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;
void bfs();
int v[1001][1001];
int time[1001][1001] = { 0, };
queue < pair<int, int>> q;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	int max = 0;
	cin >> M >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> v[i][j];
			if (v[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	bfs();
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (v[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (max < time[i][j]) max = time[i][j];
		}
	}
	cout << max;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && (v[next_x][next_y]==0)) {
				v[next_x][next_y] = 1;
				q.push(make_pair(next_x, next_y));
				//------토마토가 익는 시간 (레벨)----------
				time[next_x][next_y] = time[x][y] + 1;
			}
		}
	}
}
