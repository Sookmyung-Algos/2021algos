#include<iostream>
#include<vector>
#include<queue>
#define MAX 1e9
using namespace std;
void dijkstra(int sx, int sy);

int m, n, start_x, start_y, end_x, end_y;
int dis[1005][1005];
int adj[1005][1005];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> m >> n;

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			char a;
			cin >> a;
			switch (a) {
				case 'C':
					start_x = i;
					start_y = j;
					adj[i][j] = 0;
					break;
				case 'D':
					adj[i][j] = -1;
					break;
				case 'E':
					end_x = i;
					end_y = j;
					adj[i][j] = 0;
					break;
				case 'F':
					adj[i][j] = 1;
					break;
				case 'L':
					adj[i][j] = 5;
					break;
				case 'X':
					adj[i][j] = 10;
					break;
			}
		}
	}
	
	dijkstra(start_x, start_y);
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}
	if (dis[end_x][end_y] >= MAX) cout << "dodo sad";
	else
		cout << dis[end_x][end_y];
	return 0;
}

void dijkstra(int sx, int sy) {
	fill(&dis[0][0], &dis[1004][1005], MAX);
	priority_queue<pair<int, pair<int, int>>> pq;//{cost, start}

	pq.push({ -adj[sx][sy],{sx,sy} });
	while (!pq.empty()) {
		int cost = -pq.top().first; //cost
		int ux = pq.top().second.first; //from정점
		int uy = pq.top().second.second; //from정점
		pq.pop();

		if (cost > dis[ux][uy]) //cost가 (시작~from)보다 더 크면 가지 않는다
			continue;
		dis[ux][uy] = cost;
		for (int i = 0; i < 4;i++) {

			int vx = ux + dx[i]; //to정점
			int vy = uy + dy[i]; //to정점
			if (vx >= m || vx < 0 || vy >= n || vy < 0)
				continue;

			int now = adj[ux][uy];
			int next = adj[vx][vy];
			if (next == -1) //개가 있으면 가지 않는다
				continue;
			else if (next == 5 && dx[i] == 1) {//내려가기
				if (dis[vx][vy] > dis[ux][uy] + 5) {
					dis[vx][vy] = dis[ux][uy] + 5;
					pq.push({ -dis[vx][vy], {vx,vy} });
				}
			}
			else if (now == 5 && dx[i] == -1 && next != 10) {//올라가기
				if (dis[vx][vy] > dis[ux][uy] + 5) {
					dis[vx][vy] = dis[ux][uy] + 5;
					pq.push({ -dis[vx][vy], {vx,vy} });
				}
			}
			else if (dy[i] == -1 || dy[i] == -1) {
				if (next == 10) {//떨어지기
					while (adj[vx][vy] == 10)
						vx++;
					if (adj[vx][vy] == -1)
						continue;
					if (dis[vx][vy] > dis[ux][uy] + 11) {
						dis[vx][vy] = dis[ux][uy] + 11;
						pq.push({ -dis[vx][vy], {vx,vy} });
					}
				}
				else {//좌우
					if (dis[vx][vy] > dis[ux][uy] + 1) {
						dis[vx][vy] = dis[ux][uy] + 1;
						pq.push({ -dis[vx][vy], {vx,vy} });
					}
				}
			}
		}
	}
}

