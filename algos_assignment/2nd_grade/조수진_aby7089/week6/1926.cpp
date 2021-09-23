#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int a[501][501], n, m, cnt = 0, maxarea = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visit[501][501];
vector <pair<int, int>> v;

void dfs(int y, int x) {
	++maxarea;
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			continue;
		if (visit[ny][nx] == false && a[ny][nx] == 1)
			dfs(ny, nx);
	}
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1)
				v.push_back({ i,j });
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (visit[v[i].first][v[i].second])
			continue;
		maxarea = 0;
		dfs(v[i].first, v[i].second);
		cnt++;
		area = max(area, maxarea);
	}
	cout << cnt << "\n" << area;
}
