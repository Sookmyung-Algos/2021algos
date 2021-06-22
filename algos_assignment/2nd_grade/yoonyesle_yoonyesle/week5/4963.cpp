#include <iostream>
#include <utility>
#include <queue>
using namespace std;

bool in_map(int i, int j, int h, int w) {
	if (i < 0 || j < 0 || i >= h || j >= w)
		return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int w, h, dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	bool map[51][51];
	while (true) {
		cin >> w >> h; if (!w && !h) break;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				cin >> map[i][j];
		queue<pair<int, int>> q;
		int ans = 0;
		bool visited[51][51] = {false};
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j) {
				if (map[i][j] && !visited[i][j]) {
					q.push({i, j});
					visited[i][j] = true;
					++ans;
					while (!q.empty()) { 
						int cur_i = q.front().first, cur_j = q.front().second;
						q.pop();
						for (int k = 0; k < 8; ++k) {
							int next_i = cur_i + dir[k][0], next_j = cur_j + dir[k][1];
							if (in_map(next_i, next_j, h, w) && !visited[next_i][next_j] && map[next_i][next_j]) {
								visited[next_i][next_j] = true;
								q.push({next_i, next_j});
							}
						}
					}
				}
			}
		cout << ans << endl;
	}
	return 0;
}
