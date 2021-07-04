#include <iostream>
#include <cstring>
using namespace std;
#define MAX 301
int R, C, result = 0;
int MAP[MAX][MAX];
int temp[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx <= 0 || cy <= 0 || cx >= R + 1 || cy >= C + 1)continue;
		if (!visited[cx][cy] && MAP[cx][cy] > 0) {
			visited[cx][cy] = true;
			dfs(cx, cy);
		}
	}
}
//빙산에 인접한 바다의 개수
int zeroCnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx <= 0 || cy <= 0 || cx >= R + 1 || cy >= C + 1)continue;
		if (MAP[cx][cy] == 0)cnt += 1;
	}
	return cnt;
}

int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j) {
			cin >> MAP[i][j];
		}

	while (true) {
		int icebergCnt = 0;//빙산 덩어리 개수
		memset(visited, false, sizeof(visited));
		memset(temp, 0, sizeof(temp));

		for (int i = 1; i <= R; ++i)
			for (int j = 1; j <= C; ++j) {
				if (!visited[i][j] && MAP[i][j] > 0)
				{
					dfs(i, j);
					icebergCnt += 1;
				}
			}
		if (icebergCnt >= 2) { cout << result << "\n"; break; }
		if (icebergCnt == 0) { cout << "0" << "\n"; break; }//빙산 다 녹은 경우

		for (int i = 1; i <= R; ++i)
			for (int j = 1; j <= C; ++j) {
				if (MAP[i][j] > 0) {
					temp[i][j] = zeroCnt(i, j);
				}
			}

		for (int i = 1; i <= R; ++i)
			for (int j = 1; j <= C; ++j) {
				MAP[i][j] -= temp[i][j];
				if (MAP[i][j] < 0)MAP[i][j] = 0;
			}
		result += 1;
	}

	return 0;
}
