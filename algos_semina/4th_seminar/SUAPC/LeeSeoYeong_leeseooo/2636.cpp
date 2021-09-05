#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int n, m;
int arr[101][101];
bool visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool isAllMelted() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1)return false;
		}
	}
	return true;
}
int countCheeze() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				cnt++;
			}
		}
	}
	return cnt;
}
void bfs() {
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	visit[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n&&ny < m && !visit[nx][ny]) {
				if (arr[nx][ny] == 0) {
					q.push({ nx,ny });
				}
				else if (arr[nx][ny] == 1) {
					arr[nx][ny] = 0;
				}
				visit[nx][ny] = true;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int cheeze = 0;
	int time = 0;
	while (1) {
		if (isAllMelted())break;
		memset(visit, false, sizeof(visit));
		cheeze = countCheeze();
		bfs();
		time++;
	}
	cout << time << '\n' << cheeze;
}
