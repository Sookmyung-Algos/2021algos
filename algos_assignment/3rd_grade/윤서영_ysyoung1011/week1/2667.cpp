//2667 단지번호붙이기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, cnt = 0;
bool visit[26][26] = { false, };
int v[26][26] = { 0, };
vector<int> ans;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };

void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//cout << "x,y:" << x << ' ' << y << "nx,ny:" << nx << ' ' << ny << endl;
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (!visit[nx][ny] && v[nx][ny] == 1) {
				cnt++;
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			v[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1 && visit[i][j] == false) {
				dfs(i, j);
				ans.push_back(++cnt);
				cnt = 0;
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}
