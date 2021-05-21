#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool visit[101][101];
int map[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int m, n, k;
int cnt;
vector<int>v;

void dfs(int x, int y) {
	cnt++;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] == 0)
			dfs(nx, ny);
	}
}

int main() {
	cin >> m >> n >> k;

	while (k--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				visit[i][j] = true;
				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && !visit[i][j]) {
				cnt = 0;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	return 0;
}
