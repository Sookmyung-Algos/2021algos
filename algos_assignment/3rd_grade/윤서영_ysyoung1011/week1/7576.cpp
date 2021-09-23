#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int time[1001][1001], tomato[1001][1001];
int m, n;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		pair<int,int> node = q.front();
		int x = node.first, y = node.second;
		//cout << x << ' ' << y << endl;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && tomato[nx][ny]==0) {
				time[nx][ny] = time[x][y] + 1;
				tomato[nx][ny] = 1;
				q.push(make_pair(nx, ny));
				//cout << "time: " << time[nx][ny] << endl;
			}
		}
	}
}

int main() {
	cin >> m >> n;
	memset(time, 0, sizeof(time));
	memset(tomato, 0, sizeof(tomato));
	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) q.push(make_pair(i, j));
		}
			
		
	}
	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				cout<<"-1";
				return 0;
			}
			if (time[i][j] > ans) ans = time[i][j];
		}
	}
	cout << ans;
}
