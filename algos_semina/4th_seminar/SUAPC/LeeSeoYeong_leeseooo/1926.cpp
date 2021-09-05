#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
#include<math.h>
using namespace std;
int n, m;
int arr[501][501];
bool visit[501][501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int bfs(int a,int b) {
	int cnt = 1;
	queue<pair<int, int>>q;
	q.push({ a,b });
	visit[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n&&ny < m && !visit[nx][ny]) {
				if (arr[nx][ny] == 1) {
					cnt++;
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	int pic = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && arr[i][j] == 1) {
				int cnt = 0;
				cnt = bfs(i, j);
				ans = max(ans, cnt);
				pic++;
			}
		}
	}
	cout << pic << '\n' << ans;
}
