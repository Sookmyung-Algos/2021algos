#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define INF 987654321

using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int arr[101][101];
int dist[101][101];

queue<pair<int, int>> pq;

void dijkstra(int M, int N, int r, int c) {
   pq.push({ r,c });
   dist[r][c] = 0;

   while (!pq.empty()) {
      int ry = pq.front().first; 
      int rx = pq.front().second; 
      pq.pop();

      for (int i = 0; i < 4; i++) {

         int ty = ry + dy[i]; //nextY
         int tx = rx + dx[i]; //nextX

         if (ty < 0 || ty >= N || tx < 0 || tx >= M) continue;

         // 벽일 때
         if (arr[ty][tx] == 1) {
            if (dist[ty][tx] > dist[ry][rx] + 1) {
               dist[ty][tx] = dist[ry][rx] + 1;
               pq.push({ ty,tx });
            }
         }
         // 빈 방일 때
         else if (arr[ty][tx] == 0) {
            if (dist[ty][tx] > dist[ry][rx]) {
               dist[ty][tx] = dist[ry][rx];
               pq.push({ ty,tx });
            }
         }
      }
   }

}

int main() {

   ios::sync_with_stdio(FALSE);
   cin.tie(FALSE);

   int M, N;
   scanf("%d %d", &M, &N);

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         scanf("%1d", &arr[i][j]);
         dist[i][j] = INF;
      }
   }

   dijkstra(M, N, 0, 0);
   printf("%d", dist[N - 1][M - 1]);
   return 0;
}
