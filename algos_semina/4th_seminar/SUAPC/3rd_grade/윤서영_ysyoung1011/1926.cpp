#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans = 0, s, v[501][501], result = 0;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
bool visited[501][501] = { false, };

void dfs(int x, int y) {
	s++;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (v[nx][ny] == 1 && visited[nx][ny] == false) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j]==1 && visited[i][j]==false) {
					s = 0;
					ans++;
					dfs(i,j);
					result = max(result, s);
			}
		}
	}
	if (ans == 0) {
		cout << "0\n0";
	}
	else {
		cout << ans << '\n' << result;
	}
}
