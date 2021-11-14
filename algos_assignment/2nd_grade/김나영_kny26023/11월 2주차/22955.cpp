#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define INF 987654321
#define pp pair<int,point>
using namespace std;

typedef struct point{ 
    int x, y; 
    point(int x, int y) { 
        this->x = x; this->y = y; 
    } 
}point;

typedef struct {
	bool operator()(pp a, pp b) {
		return a.first > b.first;
	}
}cmp;

string board[1001];
int n, m;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int dist[1001][1001], score[] = { 1,5,1,5 };

bool safe(int x, int y) {
	return x >= 0 && x < m && y >= 0 && y < n && board[y][x] != 'D';
}

int dijkstra(point s, point f) {
	priority_queue<pp, vector<pp>, cmp> pq;
	fill(&dist[0][0], &dist[n][m + 1], INF);

	dist[s.y][s.x] = 0;
	pq.push(make_pair(0, s));

	while (!pq.empty()) {
		int cost = pq.top().first;
		point cur = pq.top().second; pq.pop();
		if (cost > dist[cur.y][cur.x])continue;
		if (cur.x == f.x && cur.y == f.y)return dist[cur.y][cur.x];

		if (board[cur.y][cur.x] == 'L') {
			int yy = cur.y - 1;
			if (safe(cur.x, yy) && (dist[yy][cur.x] > dist[cur.y][cur.x] + 5)) {
				dist[yy][cur.x] = dist[cur.y][cur.x] + 5;
				pq.push(make_pair(dist[yy][cur.x], point(cur.x,yy)));
			}
		}
		if (board[cur.y][cur.x] != 'X') {
			for (int i = 0; i < 3; i++) {
				int xx = cur.x + dx[i], yy = cur.y + dy[i];
				if (safe(xx, yy) && (dist[yy][xx] > dist[cur.y][cur.x] + score[i])) {
					if (i == 1 && board[yy][xx] != 'L')continue;
					dist[yy][xx] = dist[cur.y][cur.x] + score[i];
					pq.push(make_pair(dist[yy][xx], point(xx,yy)));
				}
			}
		}
		if (board[cur.y][cur.x] == 'X') {	//허공에서 추락
			int yy = cur.y + 1;
			while (safe(cur.x, yy) && board[yy][cur.x] == 'X')
				yy++;
			if (safe(cur.x, yy) && (dist[yy][cur.x] > dist[cur.y][cur.x] + 10)) {
				dist[yy][cur.x] = dist[cur.y][cur.x] + 10;
				pq.push(make_pair(dist[yy][cur.x], point(cur.x,yy)));
			}
		}
	}
	return dist[f.y][f.x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	point s = { 0,0 }, f = { 0,0 };
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'C')
				s = { j,i };
			if (board[i][j] == 'E')
				f = { j,i };
		}
	}
	int ans = dijkstra(s, f);
	if (ans == INF)
    cout << "dodo sad";
	else 
    cout << ans;
	return 0;
}
