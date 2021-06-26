#include<iostream>
#include<queue>

using namespace std;
void dfs(int x, int y);
void bfs();

queue<pair<int, int>> q;
int n, m, result=0;
int arr[301][301];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[301][301] = { false, };

int main() {
	
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];
		}
	}


	while (true) {
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				visit[i][j] = false;
			}
		}
		int cnt = 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (arr[i][j] != 0 && visit[i][j]==false) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		//분리
		if (cnt >= 2) {
			cout << result;
			break;
		}
		//분리X
		else if (q.empty()) {
			cout << 0;
			break;
		}
		//녹이기
		bfs();
		result++;
	}
	
	return 0;
}

void dfs(int x, int y) {
	visit[x][y] = true;
	q.push(make_pair(x, y));
	for (int i = 0;i < 4;i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < n&&next_y >= 0 && next_y < m && arr[next_x][next_y] != 0 && visit[next_x][next_y]==false) {
			dfs(next_x, next_y);
		}
	}
}

void bfs() {
	int melt[301][301] = { 0, };
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < n&&next_y >= 0 && next_y < m && arr[next_x][next_y] == 0) {
				melt[x][y]++;
			}
		}
	}
	//녹이기
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (arr[i][j] != 0) {
				arr[i][j] -= melt[i][j];
				if (arr[i][j] < 0)
					arr[i][j] = 0;
			}
		}
	}
}
