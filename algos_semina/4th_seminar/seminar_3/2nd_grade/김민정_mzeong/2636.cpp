#include <iostream>
#include <cstring> // memset
using namespace std;

int arr[100][100];
bool visit[100][100];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int n, m, cheese, cnt, hour;

void dfs(int y, int x) {
	if (arr[y][x]) { // 치즈가 있는 칸
		arr[y][x] = 0;
		visit[y][x] = true;
		cnt++;
		return;
	}

	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visit[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) cheese++;
		}
	}

	while (cheese > 0) {
		cnt = 0; memset(visit, false, sizeof(visit));
		dfs(0, 0);
		hour++; cheese -= cnt;
	}
	cout << hour << "\n" << cnt;
}
