#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string map[25];
bool check[25][25] = { false, };
vector<int> v;
int dx[4] = { 0, 1, 0, -1 };//북쪽부터 시계방향
int dy[4] = { -1, 0, 1, 0 };

int n, cnt;
void dfs(int i, int j);
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) cin >> map[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1' && !check[i][j]) {
				cnt = 0;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end()); //오름차순
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)	cout << v[i] << "\n";
	return 0;
}
void dfs(int i, int j) {
	check[i][j] = true;
	cnt++;

	for (int k = 0; k < 4; k++) {
		int newx = j + dx[k];
		int newy = i + dy[k];

		if (0 <= newx && newx < n && 0 <= newy && newy < n)
			if (map[newy][newx] == '1' && !check[newy][newx]) dfs(newy, newx);
		//좌표가 범위 내에 있는지, 방문한 곳인지
	}
}
