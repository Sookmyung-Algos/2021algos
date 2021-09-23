#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

bool visit[301][301];
int map[301][301] = { 0, }; //이동 횟수 저장 배열
int dx[8] = { 1,2,2,1,-1,-2,-2,-1};
int dy[8] = { -2,-1,1,2,2,1,-1,-2};
int l;
int cur_x, cur_y, x2, y2;

queue<pair<int, int>>q; //x,y

void bfs(int x, int y) {
	visit[x][y] = true;
	q.push({ x,y });

	while (!q.empty()) {
		int a = q.front().first;   //현재 위치
		int b = q.front().second;
		q.pop();

		if (a == x2 && b == y2) {   // 목적지에 도달
			cout << map[a][b] << '\n';

			while (!q.empty())
				q.pop();
			break;
		}

		for (int i = 0; i < 8; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx >= 0 && nx < l && ny >= 0 && ny < l && !visit[nx][ny]) {
				visit[nx][ny] = true;
				map[nx][ny] = map[a][b] + 1;  //이전 이동 횟수+1
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> l;
		cin >> cur_x >> cur_y >> x2 >> y2;
		bfs(cur_x, cur_y);
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
	}
	return 0;
}
