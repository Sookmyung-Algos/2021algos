#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

#define MAX 301

int N, M;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void DFS(int init_x, int init_y) {
	visit[init_x][init_y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = init_x + dx[i];
		int ny = init_y + dy[i];

		if (nx < 1 || nx >= N - 1 || ny < 1 || ny >= M - 1) continue;
		if (arr[nx][ny] > 0 && !visit[nx][ny]) DFS(nx, ny);
	}
}

void melt_ice() {
	int copy_arr[MAX][MAX];
	for (int x = 0; x < N; x++)
		for (int y = 0; y < M; y++)
			copy_arr[x][y] = arr[x][y];

	for (int x = 1; x < N; x++) {
		for (int y = 1; y < M; y++) {
			int count = 0;
			if (copy_arr[x][y] > 0) {
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (copy_arr[nx][ny] == 0) 
            count++;
				} // arr의 복사 배열 copy_arr을 통해 상하좌우 값이 0인 경우 계산, count 저장
				arr[x][y] -= count; // count 값을 빼 arr 배열 값을 수정
				if (arr[x][y] < 0) arr[x][y] = 0;
			}
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();

	cin >> N >> M;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> arr[i][j];
	
	int year = 0;
	while (1) {
		int island_count = 0;	
		bool check = false;
		memset(visit, false, sizeof(visit));

		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < M - 1; j++) {
				if (arr[i][j] > 0 && !visit[i][j]) {
					island_count++;
					if (island_count == 2) {
						check = true;
						break;
					} // 섬이 2개로 분리되었다면 while 반복 멈춤
					DFS(i, j);
				}
			}
		}
		if (check) break;
		if (island_count == 0) {
			cout << "0";
			return 0;
		} // 빙산이 다 녹을 때까지 분리되지 않으면 0 출력
		melt_ice(); // island_count가 0 또는 2가 아닐 경우
		year++;
	}
	cout << year;
	return 0;
}
