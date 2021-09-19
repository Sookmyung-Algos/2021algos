#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
int n;
char arr[101][101];
bool visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void dfs(int x,int y) {
	visit[x][y] = true;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visit[nx][ny]) {
			if (arr[x][y] == arr[nx][ny]) { //색이 같을때만 탐색
				dfs(nx, ny);
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int ans1 = 0;
	for (int i = 0; i < n; i++) { //색맹아닐때
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				dfs(i, j);
				ans1++; //구역증가
			}
		}
	}
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'G') {//빨강과 초록을 구분하지 못하므로 하나로 통일해줌
				arr[i][j] = 'R';
			}
		}
	}
	int ans2 = 0;
	for (int i = 0; i < n; i++) { //색맹일때
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				dfs(i, j);
				ans2++;
			}
		}
	}
	cout << ans1 << " " << ans2;
}
