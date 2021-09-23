#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int r, c;
char arr[21][21];
bool visit[26];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 0;
void solve(int x, int y, int cnt) {
	visit[arr[x][y] - 'A'] = true;
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < r&&ny < c) {
			if (!visit[arr[nx][ny] - 'A']) {
				solve(nx, ny, cnt + 1);
				visit[arr[nx][ny] - 'A'] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < c; j++) {
			arr[i][j] = tmp[j];
		}
	}
	solve(0, 0, 1);
	cout << ans;
}
