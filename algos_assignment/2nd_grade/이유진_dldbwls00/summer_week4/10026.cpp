#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, cnt = 0;
char picture[100][100];
bool visit[100][100] = { false,  };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (!visit[nx][ny] && picture[x][y] == picture[nx][ny])	dfs(nx, ny);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> picture[i];

	for (int i = 0; i < n; i++) {//적록색약 x
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << " ";

	for (int i = 0; i < n; i++) {//적록색약
		for (int j = 0; j < n; j++) {
			if (picture[i][j] == 'G') picture[i][j] = 'R';
			else picture[i][j] = picture[i][j];
		}
	}
	memset(visit, false, sizeof(visit)); //초기화
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
