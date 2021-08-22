#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
#define MAX 101
int n, m;
int arr[MAX][MAX];
int visit[MAX][MAX];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
void solve() {
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	visit[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m&&ny < n) {
				if (arr[nx][ny] == 1) {
					if (visit[nx][ny] > visit[x][y] + 1) {
						visit[nx][ny] = visit[x][y] + 1;
						q.push({ nx,ny });
					}
				}
				else if (arr[nx][ny] == 0) {
					if (visit[nx][ny] > visit[x][y]) {
						visit[nx][ny] = visit[x][y];
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			arr[i][j] = tmp[j] - '0';
			visit[i][j] = 987654321;
		}
	}
	solve();
	cout << visit[m - 1][n - 1];
}
