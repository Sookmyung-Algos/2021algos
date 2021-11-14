#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

#define maxx(a,b) (a > b ? a : b)
#define MAX 2147483647

int h(char c) {
	if (c >= 'a')
		return c - 'a' + 26;
	return c - 'A';
}

int get_time(char from, char to) {
	if (h(from) >= h(to))
		return 1;
	return pow(h(to) - h(from), 2);
}

int main() {
	int n, m, t, d, dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }, ans = 0;
	char map[30][30];
	scanf("%d%d%d%d", &n, &m, &t, &d);
	for (int i = 0; i < n; ++i)
		scanf("%s", map[i]);
	int visited[30][30][60];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k <= 52; ++k)
				visited[i][j][k] = -1;
	for (int i = h(map[0][0]); i; --i) visited[0][0][i] = d;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0},{d, h(map[0][0])} });
	while (!q.empty()) {
		int cur_x = q.front().first.first, cur_y = q.front().first.second;
		int cur_d = q.front().second.first, cur_max = q.front().second.second;
		q.pop();
		if (cur_x == 0 && cur_y == 0) ans = maxx(ans, cur_max);
		for (int i = 0; i < 4; ++i) {
			int next_x = cur_x + dir[i][0], next_y = cur_y + dir[i][1];
			if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m)
				continue;
			if (fabs(h(map[cur_x][cur_y]) - h(map[next_x][next_y])) > t) continue;
			int next_max = maxx(cur_max, h(map[next_x][next_y]));
			int next_d = cur_d - get_time(map[cur_x][cur_y], map[next_x][next_y]);
			if (next_d < 0) continue;
			if (visited[next_x][next_y][next_max] >= next_d) continue;
			for (int j = next_max; j >= 0; --j) {
				if (visited[next_x][next_y][j] >= next_d) break;
				visited[next_x][next_y][j] = next_d;
			}
			q.push({ {next_x, next_y}, {next_d, next_max} });
		}
	}
	printf("%d", ans);
	return 0;
}
