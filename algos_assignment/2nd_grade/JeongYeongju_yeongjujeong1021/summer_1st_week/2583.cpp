// 2583.cpp (S1)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int m, n, t, sum;
int arr[101][101], visit[101][101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<int> ans;
queue<pair<int, int>> q;

void bfs(int i, int j) {
	sum = 0;
	q.push({ i, j });
	visit[i][j] = 1;

	int a, b, x, y;
	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		q.pop();
		sum++;

		for (int k = 0; k < 4; k++) {
			x = a + dx[k];
			y = b + dy[k];
			if (0 <= x && x < n && 0 <= y && y < m
				&& !arr[x][y] && !visit[x][y]) {
				visit[x][y] = 1;
				q.push({ x, y });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n >> t;

	for (int k = 0, a, b, c, d; k < t; k++) {
		cin >> a >> b >> c >> d;
		for (int i = a; i < c; i++)
			for (int j = b; j < d; j++)
				arr[i][j] = 1;
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!arr[i][j] && !visit[i][j]) {
				cnt++;
				bfs(i, j);
				ans.push_back(sum);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << cnt << '\n';
	for (int i : ans) cout << i << ' ';
	cout << '\n';

	return 0;
}
