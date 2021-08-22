#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
bool visit[51][51] = { false, };
int a[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int test, m, n, k, x, y, ans = 0;

void dfs(int y, int x) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			continue;
		else
			if (visit[ny][nx] == false && a[ny][nx] == 1)
				dfs(ny, nx);
	}
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);	
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;  //순서 바꾸면 안 됨(문제 조건 )
			a[y][x] = 1;
			v.push_back({ y,x });
		}
		for (int i = 0; i < v.size(); i++) {
			if (visit[v[i].first][v[i].second] == true)
				continue;
			dfs(v[i].first, v[i].second);
			ans++;
		}
		cout << ans << "\n";
		v.clear(), ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = 0, visit[i][j] = false;
			}
		}
	}
}
