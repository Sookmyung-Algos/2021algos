#include <iostream>
using namespace std;

int n, ans;
int arr[16][16];
int dy[3] = { 0, 1, 1 }; // 가로, 세로, 대각선
int dx[3] = { 1, 0, 1 };

void sol(int y, int x, int pipe) {
	if (y == n - 1 && x == n - 1) {
		ans++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (pipe + i == 1) continue; // 가로->세로 또는 세로->가로 이동 불가능

		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny >= n || nx >= n || arr[ny][nx]) continue;
		if (i == 2 && (arr[y][x + 1] || arr[y + 1][x])) continue;
		sol(ny, nx, i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	sol(0, 1, 0);
	cout << ans;
}
