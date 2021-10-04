#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int arr[101][101];
bool visit[101][101];
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int n, height[101];

void dfs(int x, int y, int h) {
	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && arr[nx][ny]>h) {
			dfs(nx, ny, h);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int MAX = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			height[arr[i][j]] = 1;
			MAX = max(MAX, arr[i][j]);
		}
	}

	int res=1, cnt=0;
	for (int k = 1; k <= MAX; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j] && arr[i][j] > k) {
					dfs(i, j, k);
					cnt++;
				}
			}
		}
		res = max(cnt, res);
		cnt = 0;
		memset(visit, false, sizeof(visit));
	}

	cout << res;
	return 0;
}
