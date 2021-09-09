#include<iostream>

using namespace std;

char arr[251][251];
bool visit[251][251];
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int r, c;
int s = 0, w = 0;

void dfs(int x, int y) {
	visit[x][y] = true;

	if (arr[x][y] == 'v') {
		w++;
	}
	if (arr[x][y] == 'o') {
		s++;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
			if (!visit[nx][ny] && arr[nx][ny] != '#')
				dfs(nx, ny);
		}
	}
	return;
}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	int sheep = 0, wolf = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!visit[i][j] && arr[i][j] != '#') {
				s = 0, w = 0;
				dfs(i, j);
				if (s <= w) {
					wolf += w;
				}
				else {
					sheep += s;
				}
			}
		}
	}

	cout << sheep << ' ' << wolf;
}
