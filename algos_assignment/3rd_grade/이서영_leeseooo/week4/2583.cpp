#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<memory.h>
#include<tuple>
#include<queue>
using namespace std;
int m, n, k;
int ans = 0;
bool visit[101][101];
int arr[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void check(int x1,int x2,int y1,int y2) {
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			arr[i][j] = 1;
		}
	}
}
void dfs(int x,int y) {
	visit[x][y] = true;
	ans++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m&& !visit[nx][ny] && !arr[nx][ny]) {
			dfs(nx, ny);
		}
	}
}
int main() {
	int x1, x2, y1, y2;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		check(x1, x2, y1, y2);
	}
	vector<int>v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 1 && visit[i][j] == false) {
				ans = 0; //초기화 까먹지 말고 시켜주삼
				dfs(i,j);
				v.push_back(ans);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}
// 이차원일때 가로세로 계속 헷갈리는 나자식
// 헹 => 가로인데 세로로 셈 , 열 => 세로인데 가로로 셈
// 가로가 x 세로가 y이므로 가로로 셈해나가는 열, 세로로 셈해나가는 행 순으로 반복문 돌려줘야됨
