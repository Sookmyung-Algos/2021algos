#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, l;
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
int curx, cury;
int goalx, goaly;
int pan[310][310];
bool visited[310][310];
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == goalx && y == goaly) {
			cout << pan[x][y] << "\n";
			return;
		}

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visited[nx][ny] == 1)
				continue;
			if (nx >= 0 && ny >= 0 && nx < l && ny < l) {
				pan[nx][ny] = pan[x][y] + 1; // 이전 지점까지의 횟수에서 1 더하기
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		q = queue<pair<int,int>> (); // 큐 초기화
		cin >> l; // 한 변 길이
		for (int j = 0; j < l; j++) {
			for (int k = 0; k < l; k++) {
				pan[j][k] = 0;
				visited[j][k] = 0;
			}
		}
		cin >> curx >> cury;
		q.push({ curx,cury });
		cin >> goalx >> goaly;
		bfs();
	}
	
}
