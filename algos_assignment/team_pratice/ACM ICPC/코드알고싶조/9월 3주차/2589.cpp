#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m, res = 0;
bool map[51][51];
int d[51][51];
bool v[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int i, int j) {
	queue<pair<int, int>> q;

	v[i][j] = 1;
	q.push({ i,j });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m && !v[nx][ny] && map[nx][ny]) { // 범위 안이고 방문x, 육지일때
				v[nx][ny] = 1;
				d[nx][ny] = d[x][y] + 1;
				q.push({ nx,ny });
				res = max(res, d[nx][ny]);
			}
		}	
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == 'L')
				map[i][j] = 1;
			else if (c=='W')
				map[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) {
				bfs(i,j);
				memset(v, 0, sizeof(v));
				memset(d, 0, sizeof(d));
				
			}
		}
	}
	cout << res;
}
