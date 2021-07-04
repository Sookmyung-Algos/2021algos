#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 301;

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

		if (nx < 1 || nx >= N - 1 || ny < 1 || ny >= M - 1)
			continue;
		if (arr[nx][ny] > 0 && !visit[nx][ny])
			DFS(nx, ny);
	}
}

void melt_ice() {
	int cArr[MAX][MAX];
	for (int x = 0; x < N; x++)
		for (int y = 0; y < M; y++)
			cArr[x][y] = arr[x][y];

	for (int x = 1; x < N; x++) {
		for (int y = 1; y < M; y++) {
			int count = 0;

			if (cArr[x][y] > 0) {
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (cArr[nx][ny] == 0) count++;
				}
				arr[x][y] -= count;

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
		int isCount = 0;
		bool check = false;
		memset(visit, false, sizeof(visit));

		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < M - 1; j++) {
				if (arr[i][j] > 0 && !visit[i][j]) {
					isCount++;
					if (isCount == 2) {
						check = true;
						break;
					}
					DFS(i, j);
				}
			}
		}
		if (check) break;
		if (isCount == 0) {
			cout << "0" << '\n';
			return 0;
		}
		melt_ice();
		year++;
	}
	cout << year << '\n';
	return 0;
}
