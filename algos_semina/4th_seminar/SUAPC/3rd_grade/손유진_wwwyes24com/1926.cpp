#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, sum = 0, area = 0, big = 0;
int pic[510][510];
int visit[510][510];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs(int i, int j) {
	queue<pair<int, int>> q;
	area = 1;
	visit[i][j] = 1;
	q.push({ i,j });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m && pic[nx][ny] && !visit[nx][ny]) {
				visit[nx][ny] = 1;
				q.push({ nx,ny });
				area++;
			}
		}
	}
	return area;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) 
			cin >> pic[i][j];		
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pic[i][j] && !visit[i][j]) {
				sum++; // 개수
				big = max(bfs(i, j), big);
			}
		}
	}
	cout << sum << "\n" << big;

}
