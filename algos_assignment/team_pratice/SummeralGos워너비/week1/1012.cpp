//#1012
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int t, m, n, k;
//t;테스트 케이스의 개수
//m;배추밭 가로길이
//n;배추밭 세로길이
//k;배추 심어져 있는 위치 개수

int x, y;
int farm[51][51];
int visited[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void reset() { //테스트 케이스마다 farm 배열과 visited 배열 초기화
	for(int i=0;i<n;i++){
		for (int j = 0; j < m; j++) {
			farm[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}
void dfs(int x, int y) { //x가 세로기준, y가 가로기준
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) { //현재위치로부터 동서남북 4방향 확인
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (farm[nx][ny] == 1 && visited[nx][ny] == 0) {
				dfs(nx, ny); //배추가 있으면서 동시에 방문하지 않은 곳이라면 dfs 재귀함수 호출
			}
		}
	}
}

int main() {
	scanf("%d", &t);

	while (t--) { //t개의 테스트 케이스 
		scanf("%d %d %d", &m, &n, &k);

		reset();

		for (int i = 0; i < k; i++) {
			scanf("%d %d", &y, &x);
			farm[x][y] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (farm[i][j] == 1 && visited[i][j] == 0) {
					dfs(i, j);
					cnt++; //각각의 배추 묶음내에서 dfs 재귀함수가 끝난 후에 cnt 1 증가
				}
			}
		}

		cout << cnt << endl;
	}
}
