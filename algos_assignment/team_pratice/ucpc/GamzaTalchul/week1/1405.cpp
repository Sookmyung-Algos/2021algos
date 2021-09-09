#include <iostream>
#include <algorithm>
using namespace std;
int visit[29][29];
int n;
double ans = 0, per[4];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs(int x, int y, int cnt, double res) {
	if (cnt == n) {
		ans += res;
		return;
	}
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!visit[nx][ny]) {
			dfs(nx, ny, cnt + 1, res*per[i]);
		}
	}
	visit[x][y] = 0;
}

int main() {
	double p;
	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> p;
		per[i] = p / 100;
	}
	dfs(14, 14, 0, 1.0);
	cout.precision(10);  //소수점 아래 10자리까지 출력
	cout << fixed << ans;
}
