#include <iostream>
#include <algorithm>
using namespace std;

int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}, n;
char map[25][25];

int dfs(int x, int y) {
	if (x >= n || y >= n || x < 0 || y < 0)
		return 0;
	if (map[x][y] == '0')
		return 0;
	map[x][y] = '0';
	int ret = 1;
	for (int i = 0; i < 4; ++i)
		ret += dfs(x + dir[i][0], y + dir[i][1]);
	return ret;
}

int main() {
	int cnt = 0, house[313];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", map[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == '1')
				house[cnt++] = dfs(i, j);
		}
	sort(house, house + cnt);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i)
		printf("%d\n", house[i]);
	return 0;
}
