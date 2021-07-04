#include <iostream>
#include <algorithm>
#include <cstring> // memset
using namespace std;

const int MAX = 300;

typedef struct {
	int y, x;
}Dir;

Dir dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N, M;
int arr[MAX][MAX];
bool visited[MAX][MAX];

void melt() {
	int copy[MAX][MAX];
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			copy[y][x] = arr[y][x];

	for (int y = 1; y < N - 1; y++)
		for (int x = 1; x < M - 1; x++)
			if (copy[y][x]) {
				int cnt = 0;
				for (int i = 0; i < 4; i++) { // 동서남북 0 개수 세기
					int nextY = y + dir[i].y;
					int nextX = x + dir[i].x;
					if (copy[nextY][nextX] == 0) cnt++;
				}
				arr[y][x] = max(copy[y][x] - cnt, 0); // 각 칸에 저장된 높이는 0보다 더 줄어들지 않음
			}
}

void DFS(int y, int x) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int nextY = y + dir[i].y;
		int nextX = x + dir[i].x;
		if (1 <= nextY && nextY < N - 1 && 1 <= nextX && nextX < M - 1)
			if (arr[nextY][nextX] && !visited[nextY][nextX])
				DFS(nextY, nextX);
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	int year = 0; // 빙산 분리 시간
	while (1) {
		memset(visited, false, sizeof(visited)); // false로 초기화

		bool result = false;
		int cnt = 0;

		for (int y = 1; y < N - 1; y++)
			for (int x = 1; x < M - 1; x++)
				if (arr[y][x] && visited[y][x] == false) { // 해당 좌표에 빙산도 있고 방문한 적도 없음
					cnt++;
					if (cnt == 2) {
						result = true;
						break;
					}
					DFS(y, x);
				}
		if (result) break;
		if (cnt == 0) {
			year = 0;
			break;
		}
		melt();
		year++;
	}
	cout << year << "\n";
}
