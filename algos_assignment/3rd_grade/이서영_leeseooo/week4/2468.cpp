#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<memory.h>
#include<tuple>
#include<queue>
using namespace std;
int n;
int MaxRain = 0;
int arr[101][101];
bool visit[101][101];
queue<pair<int, int>>q;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
void bfs(int rain) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny<n && !visit[nx][ny] && arr[nx][ny]>rain) {
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			MaxRain = max(MaxRain, arr[i][j]);
		}
	}
	int ans = 0;
	for (int rain = 0; rain < MaxRain; rain++) {//가능한 비의 높이마다 탐색
		memset(visit, false, sizeof(visit));
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > rain && !visit[i][j]) {//높이가 강수량보다 높고 방문하지 않은 곳
					q.push({ i,j }); // 즉 안전한 곳을 queue에 담는다.
					visit[i][j] = true; //방문 체크
					bfs(rain);

					res++; //안전영역 증가
				}
			}
		}
		ans = max(ans, res);//최대 안전영역 개수 저장
	}
	cout << ans;
}
