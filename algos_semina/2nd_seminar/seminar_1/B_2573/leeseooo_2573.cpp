#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n, m;
int arr[301][301];
int arr_copy[301][301];//cnt는 arr에서 세고 빙산녹이는건 copy배열에서 (새로 0되는거 또 세면 안돼서)
bool visit[301][301];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int iceberg;
int year = 0;
void bfs(int a,int b) {
	queue<pair<int, int>>q;
	q.push({ a,b });
	visit[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visit[nx][ny]) {
				if (arr[nx][ny] != 0) {
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
		}
	}
}
int countWater(int x,int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (arr[nx][ny] == 0) cnt++;
	}
	return cnt;
}
void copyArr() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr_copy[i][j];
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		iceberg = 0;//빙산 개수 갱신
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] && !visit[i][j]) {
					bfs(i, j);
					iceberg++;
				}
			}
		}
		if (iceberg >= 2) {
			cout << year;
			break;
		}
		if (iceberg == 0) {
			cout << 0;
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					arr_copy[i][j] = arr[i][j] - countWater(i, j);
					if (arr_copy[i][j] < 0) arr_copy[i][j] = 0;
				}
			}
		}
		copyArr();
		year++;
	}
}
