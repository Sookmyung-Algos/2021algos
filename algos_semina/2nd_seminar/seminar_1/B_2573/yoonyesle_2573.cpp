#include <iostream>
using namespace std;

int n, m, year, map[301][301], dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

void dfs(int x, int y, bool visited[][301]) {
	visited[x][y] = true;
	for (int k = 0; k < 4; ++k) {
		int i = x + dir[k][0], j = y + dir[k][1];
		if (i >= 0 && j >= 0 && i < n && j < m && map[i][j] > 0 && !visited[i][j]) {
			dfs(i, j, visited);
		}
	}
}

bool finish() {
	bool visited[301][301] = {false};
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (map[i][j] != 0 && !visited[i][j]) {
				++cnt;
				dfs(i, j, visited);
			}
		}
	if (cnt >= 2)
		printf("%d", year);
	else if (cnt == n * m || cnt == 0)
		printf("0");
	if (cnt >= 2 || cnt == n * m || cnt == 0)
		return true;
	return false;
}

int count(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int next_x = x + dir[i][0], next_y = y + dir[i][1];
		if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m)
			continue;
		if (map[next_x][next_y] == 0)
			++cnt;
	}
	return cnt;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &map[i][j]);
	while (true) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (map[i][j] < 0) map[i][j] = 0;
		if (finish())
			return 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (map[i][j]) {
					map[i][j] -= count(i, j);
					if (map[i][j] == 0) map[i][j] = -1;
				}
			}
		++year;
	}
	return 0;
}
