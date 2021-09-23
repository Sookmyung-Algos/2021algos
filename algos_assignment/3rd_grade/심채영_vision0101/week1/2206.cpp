#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> PAIR;
#define X first
#define Y second

char board[1004][1004];
int N, M;
int dist1[1004][1004];
int dist2[1004][1004];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", board[i]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dist1[i][j] = dist2[i][j] = -1;

	queue<PAIR> Q;
	Q.push({ 0,0 });
	dist1[0][0] = 1;
	while (!Q.empty()) {
		PAIR cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int x = cur.X + dx[dir];
			int y = cur.Y + dy[dir];
			if (x < 0 || x >= N || y < 0 || y >= M || board[x][y] == '1' || dist1[x][y] != -1)
				continue;
			dist1[x][y] = dist1[cur.X][cur.Y] + 1;
			Q.push({ x,y });
		}
	}
	Q.push({ N - 1, M - 1 });
  
	dist2[N - 1][M - 1] = 1;
	while (!Q.empty()) {
		PAIR cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int x = cur.X + dx[dir];
			int y = cur.Y + dy[dir];
			if (x < 0 || x >= N || y < 0 || y >= M || board[x][y] == '1' || dist2[x][y] != -1)
				continue;
			dist2[x][y] = dist2[cur.X][cur.Y] + 1;
			Q.push({ x,y });
		}
	}
  
	int min_dist = 0x7fffff;
	if (dist2[0][0] >= 0) 
		min_dist = dist2[0][0]; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0)
				continue;
			
			int min_dist1 = 0x7fffff;
			int min_dist2 = 0x7fffff;
			for (int dir = 0; dir < 4; dir++) {
				int x = i + dx[dir];
				int y = j + dy[dir];
				if (x < 0 || x >= N || y < 0 || y >= M)
					continue;
				if (dist1[x][y] >= 0)
					min_dist1 = min(min_dist1, dist1[x][y]);
				if (dist2[x][y] >= 0)
					min_dist2 = min(min_dist2, dist2[x][y]);
			}
			min_dist = min(min_dist, min_dist1 + min_dist2+1);
		}
	}
  
	if (min_dist == 0x7fffff)
		printf("-1");
	else
		printf("%d", min_dist);
	return 0;
}
