#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int arr[501][501];
bool visited[501][501];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	int n, m;
	cin >> n >> m;
	queue<pair<int, int> > q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)	cin >> arr[i][j];
	}

	int num = 0, max = 0, area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || arr[i][j] == 0)	continue;
			visited[i][j] = 1;
			q.push({ i,j });
			area = 0;
			num++;

			while (!q.empty()) { //참고
				pair<int, int> now = q.front();
				q.pop();
				area++;
				for (int direction = 0; direction < 4; direction++) {
					int nx = now.first + dx[direction];
					int ny = now.second + dy[direction];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;
					if (visited[nx][ny] || arr[nx][ny] == 0)	continue;
					visited[nx][ny] = 1;
					q.push({ nx,ny });
				}
				if (max < area)	max = area;
			}
		}
	}
	cout << num << "\n" << max;
	return 0;
}
