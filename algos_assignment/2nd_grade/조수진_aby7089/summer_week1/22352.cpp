#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int sp[31][31], cp[31][31];
bool chk[31][31];
int n, m, num = 0;

bool bfs(int i, int j) {
	chk[i][j] = true;
	int bf = sp[i][j];
	sp[i][j] = cp[i][j];	
	q.push(make_pair(i, j));
	while (!q.empty()) {
		auto cur = q.front(); 
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cur.first + dx[k], ny = cur.second + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;  //범위 내인지 확인
			if (chk[nx][ny] || sp[nx][ny] != bf) continue;  //연결된 부분이 아니거나 방문한 경우
			sp[nx][ny] = cp[i][j];
			chk[nx][ny] = true;
			q.push(make_pair(nx, ny));
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (sp[i][j] != cp[i][j]) 
				return false;
		}
	}
	return true;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> sp[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cp[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (sp[i][j] != cp[i][j]) {
				bool ans=bfs(i, j);
				if (ans) cout << "YES";
				else cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";  //백신을 놓은 후에도 모든 값이 똑같은 경우 존재함.
}
