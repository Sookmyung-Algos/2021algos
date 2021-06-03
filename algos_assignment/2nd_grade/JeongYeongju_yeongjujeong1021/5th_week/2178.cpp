#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int arr[MAX][MAX];
int visit[MAX][MAX];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<pair<int, int>, int>> q;
int n, m, ans = MAX*MAX;

void bfs(int i, int j) {
	int x, y, z;
	visit[i][j] = 1;
	q.push({ { i, j }, 1 });
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		z = q.front().second;
		q.pop();
		if (x == n - 1 && y == m - 1)
			ans = min(ans, z);
		for (int k = 0; k < 4; k++) {
			i = x + dx[k]; j = y + dy[k];
			if (0 <= i && i < n && 0 <= j && j < m
				&& !visit[i][j]) {
				visit[i][j] = 1;
				q.push({ { i, j }, z + 1 });
			}
		}
	}
}

int main() {
	char str[MAX];
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j] - '0';
			if (arr[i][j]) visit[i][j] = 0;
			else visit[i][j] = 1;
		}
	}

	bfs(0, 0);

	cout << ans << '\n';
}
