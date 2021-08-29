#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector <pair<int, int>> v;
int map[51][51];
bool visit[51][51];
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
int w, h;

void dfs(int y, int x) {
	visit[y][x] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= w || ny < 0 || ny >= h)
			continue;
		if (visit[ny][nx] == false && map[ny][nx] == 1)
			dfs(ny, nx);
	}
		
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);	
	int ans = 0;
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1)
					v.push_back({ i,j });
			}
		}
		for (int i = 0; i < v.size(); i++) {
			if (visit[v[i].first][v[i].second] == false) {
				dfs(v[i].first, v[i].second);
				ans++;
			}
		}
		cout << ans << "\n";
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				map[i][j] = 0, visit[i][j] = false;
			}
		}
		v.clear(), ans = 0;
	}
}
