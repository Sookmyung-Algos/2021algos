#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 26

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int arr[MAX][MAX];
int visit[MAX][MAX];
int ans[MAX*MAX];
int n;
queue<pair<int,int>> q;

int bfs(int i, int j) {
	int cnt = 0, x, y;
	visit[i][j] = 1;
	q.push({ i, j });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		cnt++;
		for (int k = 0; k < 4; k++) {
			i = x + dx[k]; j = y + dy[k];
			if (0 <= i && i < n && 0 <= j && j < n
				&& visit[i][j] == 0) {
				visit[i][j] = 1;
				q.push({ i, j });
			}
		}
	}
	return cnt;
}

int main() {
	int index = 0, sum = 0;
	char str[MAX];
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j] - '0';
			if (arr[i][j])
				visit[i][j] = 0;
			else
				visit[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] && !visit[i][j]) {
				ans[index++] = bfs(i, j);
				sum++;
			}
		}
	}

	sort(ans, ans + index);

	cout << sum << '\n';
	for (int i = 0; i < index; i++)
		cout << ans[i] << '\n';

	return 0;
}
