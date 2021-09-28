#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int a, b, ans;

int arr[101][101];
int visit[101][101];

queue<pair<int, int>> q;

int bfs(int cnt) {
	ans = 0;
	memset(visit, -1, sizeof(visit));
	q.push({ 0, 0 });
	visit[0][0] = 0;
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];

			if (0 <= x && x < a && 0 <= y && y < b) {
				if (!arr[x][y] && visit[x][y] == -1) {
					visit[x][y] = 0;
					q.push({ x, y });
				}
				else if (arr[x][y] && visit[x][y] == -1) {
					visit[x][y] = cnt;
					ans++;
				}
			}
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (visit[i][j] == cnt)
				arr[i][j] = 0;
		}
	}

	return ans;
}

int check() {
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			if (arr[i][j] == 1) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	for (int i = 0; i < a; i++) for (int j = 0; j < b; j++) cin >> arr[i][j];

	int t = 0, ans = 0;
	while (!check()) { ans = bfs(++t); }

	cout << t << '\n' << ans << '\n';

	return 0;
}
