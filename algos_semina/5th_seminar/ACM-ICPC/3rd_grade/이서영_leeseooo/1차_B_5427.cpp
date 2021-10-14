#include <iostream>
#include <algorithm>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;
int t, w, h;
char arr[1001][1001];
bool visit[1001][1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int, int>>fire;
int bfs(int a, int b) {
	queue<pair<int, int>>q;
	q.push({ a,b });
	queue<pair<int, int>>fq;
	int ttime = 0;
	for (int i = 0; i < fire.size(); i++) {
		fq.push({ fire[i].first,fire[i].second });
	}
	while (!q.empty()) {
		int size = fq.size();
		for (int j = 0; j < size; j++) {
			int x = fq.front().first;
			int y = fq.front().second;
			fq.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < h && ny < w) {
					if (arr[nx][ny] == '.') {
						arr[nx][ny] = '*';
						fq.push({ nx,ny });
					}
				}
			}
		}
		size = q.size();//매 초 움직일수 있는 q 좌표는 다 탐색해야함
		for (int j = 0; j < size; j++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == 0 || y == 0 || x == h - 1 || y == w - 1) return ttime + 1;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < h&&ny < w && !visit[nx][ny]) {
					if (arr[nx][ny] == '.') {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		ttime++;
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		memset(visit, false, sizeof(visit));
		fire.clear();
		int x, y;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@') {
					x = i; y = j;
				}
				else if (arr[i][j] == '*') {
					fire.push_back({ i,j });
				}
			}
		}
		int res = bfs(x, y);
		if (res == -1)cout << "IMPOSSIBLE\n";
		else cout << res << '\n';
	}
}
