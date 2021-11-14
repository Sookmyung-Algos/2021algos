#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1e9
#define MAX 110

using namespace std;

int n, m;
int dist[MAX][MAX];
int map[MAX][MAX];

int dx[4] = { 1, -1, 0, 0 }; // x축 움직이기
int dy[4] = { 0,0,1,-1 }; // y축 움직이기

void dijikstra() {
	// 어디서 왔는지, 그 가중치가 얼마인지
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int, int>>>> pq;

	pq.push({ 0,{1,1} });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int node_x = pq.top().second.second;
		int node_y = pq.top().second.first;

		pq.pop();

		for (int i = 0; i < 4; i++) { // 동서남북 네 방향 탐색
			int next_x = node_x + dx[i]; // 다음방의 x좌표
			int next_y = node_y + dy[i]; // 다음방의 y좌표

			if (next_x > m || next_y > n || next_x <= 0 || next_y <= 0) continue; // 다음 이동하는 방이 미로의 밖이라면 다른 방향으로 계속 진행

			int next_cost = cost + map[next_y][next_x]; // 벽의 유무를 포함하여 저장

			// 다음 방으로 이동
			if (dist[next_y][next_x] > next_cost) { 
				dist[next_y][next_x] = next_cost;
				pq.push({ next_cost,{next_y,next_x} });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < MAX; i++) { // 모든 방의 값을 1e9로 초기화
		for (int j = 0; j < MAX; j++) {
			dist[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; i++) { // 미로의 상태 입력받음
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	dist[1][1] = 0;
	dijikstra();

	cout << dist[n][m]; // 결과 출력
}
