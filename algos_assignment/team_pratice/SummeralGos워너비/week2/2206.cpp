//#2206 벽 부수고 이동하기
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int map[1001][1001];
int visit[1001][1001][2]; //현재위치 x,y,벽을 부수었는지 유무

int crash(void) {
	queue<pair<pair<int, int>, pair<int, int>>> q; //<현재위치x,y>,<벽을 부순 횟수,현재까지 이동거리>
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	visit[0][0][0]=1; //x,y,벽을부순횟수(같은 정점을 방문하더라도 벽을 부수고 온 것인지 벽을 부수지 않고 온 것인지에 따라 다른 경로가 됨)

	int x, y, b, cnt;

	while (q.empty() == 0) { //q가 비지 않았으면
		x = q.front().first.first;
		y = q.front().first.second;
		b = q.front().second.first;
		cnt = q.front().second.second;
		q.pop();

		if (x == n - 1 && y == m - 1) return cnt; //종점에 도착했다면 거리 리턴
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx>=0&&ny>=0&&nx<n&&ny<m){ //map안에 존재할 때
				if (map[nx][ny] == 1 && b == 0) { //다음 경로가 벽이고 아직 벽을 부수지 않았을 때
					visit[nx][ny][b + 1] = 1; //그 위치의 벽을 부순 횟수를 1 증가하고 방문한 것으로 표시
					q.push(make_pair(make_pair(nx, ny), make_pair(b + 1, cnt + 1))); //그 위치에 벽부순 횟수+1와 이동거리+1까지 pair로 묶어 q에 push
				}
				else if (map[nx][ny] == 0 && visit[nx][ny][b] == 0) { //다음 경로가 벽이 아니고 아직 방문하지 않은 경로일 때
					visit[nx][ny][b] = 1; //그 위치를 방문한 것으로 표시
					q.push(make_pair(make_pair(nx, ny), make_pair(b, cnt + 1))); //벽은 부수지 않았으니까 그대로, 이동거리는 1 증가하여 q push
				}
			}
		}
	}

	return -1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d",&map[i][j]); //한자리만 각각 원소로 받아야 하므로 1d
		}
	}

	int result=crash();
	printf("%d", result);
	return 0;
}
