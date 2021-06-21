#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
string arr[100]; // 미로
int check[100][100] = {0,}; // 지나온 칸 수 저장용
bool v[100][100] = {false,}; // 방문 확인용
int dx[4] = {0, 1, 0, -1}; // 북, 동, 남, 서
int dy[4] = {1, 0, -1, 0};

void bfs(int i, int j) {
	v[i][j] = true;

	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int newX = x + dx[k];
			int newY = y + dy[k];
			if (0 <= newX && newX < m && 0 <= newY && newY < n && arr[newY][newX] == '1' && !v[newY][newX] && check[newY][newX] == 0) {
				check[newY][newX] = check[y][x] + 1;
				v[newY][newX] = true;
				q.push(make_pair(newY, newX));
			} // 해당 좌표가 범위 안에 있는지 확인, 갈 수 있는지(1) 확인, 방문한 적 없는지 확인
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	bfs(0, 0);
	cout << check[n-1][m-1]+1;
}
