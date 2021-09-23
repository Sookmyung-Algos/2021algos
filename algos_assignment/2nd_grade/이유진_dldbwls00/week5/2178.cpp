#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
string maze[100]; // 미로
int cnt[100][100] = { 0, };
bool v[100][100] = { false, }; //확인
int dx[4] = { 0, 1, 0, -1 }; // 북,동,남,서(시계방향)
int dy[4] = { 1, 0, -1, 0 };

void bfs(int x, int y);

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> maze[i];
	bfs(0, 0);
	cout << cnt[n - 1][m - 1] + 1;
}
void bfs(int x, int y) {
	v[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int newx = x + dx[k];
			int newy = y + dy[k];
			if ((newx >= 0 && newx < m) && (newy >= 0 && newy < n) && maze[newy][newx] == '1' && !v[newy][newx] && cnt[newy][newx] == 0) {
				//좌표가 범위 내에 있는지, 방문한 곳인지
				cnt[newy][newx] = cnt[y][x] + 1;
				v[newy][newx] = true;
				q.push({ newy, newx });
			}
		}
	}
}
