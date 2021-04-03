#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int map[1002][1002], check[1002][1002];
queue<pair<int, int>> q;
int xmap[] = { 1,0,-1,0 };
int ymap[] = { 0,-1,0,1 };
int n, m;
void bfs() {
	int a, b, xa, yb;

	while (!q.empty()) {
		b = q.front().first;
		a = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			xa = a + xmap[i];
			yb = b + ymap[i];
			if (0 <= xa && xa <= m - 1 && 0 <= yb && yb <= n - 1) {
				if (map[yb][xa] == 0 && check[yb][xa] == 0) {
					q.push({ yb,xa });
					check[yb][xa] = check[b][a] + 1;
				}
			}
		}
	}
}
int main() {

	int min = 0;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 0 && map[i][j] == 1) {
				q.push({ i,j });
				check[i][j] = 1;
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] - 1 > min)
				min = check[i][j] - 1;
			if (map[i][j] == 0 && check[i][j] == 0) {
				cout << -1 << '\n';
				exit(0);
			}
		}
	}
	cout << min << '\n';
}
