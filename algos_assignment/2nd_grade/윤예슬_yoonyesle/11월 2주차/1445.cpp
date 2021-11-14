#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, w;
	bool operator<(const node& b) const {
		return w > b.w;
	}
};

char map[51][51];
int n, m, dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int check_ng(int x, int y) {
	for (int k = 0; k < 4; ++k) {
		int i = x + dir[k][0], j = y + dir[k][1];
		if (i < 0 || j < 0 || i >= n || j >= m)
			continue;
		if (map[i][j] == 'g')
			return 1;
	}
	return 0;
}

int check_g(int x, int y) {
	if (map[x][y] == 'g')
		return 1;
	return 0;
}
#define DIV 2500

int main() {
	int sx, sy, fx, fy;
	scanf("%d%d", &n, &m);
	int weight[51][51] = { 0 };
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; map[i][j]; ++j) {
			weight[i][j] = check_g(i, j) ? DIV : check_ng(i, j);
			if (map[i][j] == 'S') {
				sx = i; sy = j; weight[i][j] = 0;
			}
			else if (map[i][j] == 'F') {
				fx = i; fy = j; weight[i][j] = 0;
			}
		}
	priority_queue<node> pq;
	bool visit[51][51] = { false };
	pq.push({ sx, sy, weight[sx][sy] }); visit[sx][sy] = true;
	int d[51][51]; d[sx][sy] = weight[sx][sy];
	while (!pq.empty()) {
		node cur = pq.top(); pq.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (visit[nx][ny] && d[nx][ny] <= cur.w + weight[nx][ny])
				continue;
			visit[nx][ny] = true;
			d[nx][ny] = cur.w + weight[nx][ny];
			pq.push({ nx, ny, d[nx][ny] });
		}
	}
	printf("%d %d", d[fx][fy] / DIV, d[fx][fy] % DIV);
	return 0;
}
