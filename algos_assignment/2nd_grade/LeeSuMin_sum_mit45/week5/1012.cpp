#include <iostream>
#include <string.h>
using namespace std;

int testcase;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0,1,0,-1 };

int M, N;
bool check[51][51];
bool land[51][51]; 

// dfs 구현
void dfs(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || nx >= M || ny >= N) continue;

		if (land[nx][ny] == true && !check[nx][ny])
		{
			check[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}


int main() {
	int cnt;
	cin >> cnt;

	for (int testCnt = 0; testCnt < cnt; testCnt++) {

		int k;
		cin >> M >> N >> k;

		memset(land, false, sizeof(land));
		memset(check, false, sizeof(check));
		int ans = 0;

		for (int i = 0; i < k; i++) {
			int a, b; cin >> a >> b;
			land[a][b] = true;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {

				if (land[i][j] == true && !check[i][j]) {
					ans++;
					dfs(i, j);
				}
			}
		}

		cout << ans << '\n';

	}

	return 0;
}
