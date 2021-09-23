// 2468.cpp (S1)

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n;
int arr[101][101], visit[101][101];

queue<pair<int, int>> q;

void bfs(int i, int j, int h) {
	q.push({ i, j });
	visit[i][j] = 1;

	pair<int, int> cur, next;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			next = { cur.first + dx[k], cur.second + dy[k] };
			if (0 < next.first && next.first <= n
				&& 0 < next.second && next.second <= n
				&& arr[next.first][next.second] > h
				&& !visit[next.first][next.second]) {
				visit[next.first][next.second] = 1;
				q.push(next);
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int max_h = 0, min_h = 101;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			max_h = max(max_h, arr[i][j]);
			min_h = min(min_h, arr[i][j]);
		}
	}

	int ans = 0, cnt;
	for (int k = min_h - 1; k < max_h; k++) {
		cnt = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!visit[i][j] && arr[i][j] > k) {
					bfs(i, j, k);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans << '\n';

	return 0;
}
