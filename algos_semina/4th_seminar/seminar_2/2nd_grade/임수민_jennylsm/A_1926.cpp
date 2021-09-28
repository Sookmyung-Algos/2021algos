#include <iostream>
#define MAX 500
using namespace std;

bool arr[MAX][MAX]; 
bool visited[MAX][MAX]; // 방문 기록

int mov[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 상 하 좌 우
int m, n;
int cnt; // DFS 크기
int picCnt = 0; 
int maxSize = 0; // 가장 넓은 그림

bool isInArr(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m ? true : false;
}

void DFS(int x, int y) {
	int nx, ny;
	for (int i = 0; i < 4; ++i) {
		nx = x + mov[i][0];
		ny = y + mov[i][1];
		//방문한 적 없다면
		if (isInArr(nx, ny) && arr[nx][ny] && !visited[nx][ny]) {
			visited[nx][ny] = true;
			cnt++; // cnt 누적
			DFS(nx, ny);
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!visited[i][j] && arr[i][j]) {
				picCnt++;
				cnt = 1; 
				visited[i][j] = true;
				DFS(i, j); // arr[i][j]를 방문하지 않았고 값이 1이라면 DFS
				if (cnt > maxSize) maxSize = cnt; // cnt가 maxSize보다 크다면 갱신
			}

		}
	}
	cout << picCnt << "\n" << maxSize << "\n";
}
