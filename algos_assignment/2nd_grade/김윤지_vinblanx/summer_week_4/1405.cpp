#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> P;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
double dir[4];
int visited[30][30];
int n;
double res;

void DFS(P now, double pro) {
	int x = now.first;
	int y = now.second;
	if (visited[x][y] == n + 1) {
		res += pro;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visited[nx][ny])
			continue;
		visited[nx][ny] = visited[x][y] + 1;
		DFS({ nx,ny }, pro * dir[i]);
		visited[nx][ny] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	cin >> n;
	for (int i = 0; i < 4; i++) {
		double x; cin >> x;
		dir[i] = x / 100;
	}
	visited[15][15] = 1;
	DFS(P(15, 15), 1.0);
    cout.precision(10);
	cout << fixed << res << "\n";
    
	return 0;
}
