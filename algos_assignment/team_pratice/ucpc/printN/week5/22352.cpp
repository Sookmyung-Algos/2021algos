#include <iostream>
#include <queue>

using namespace std;

int bef[30][30], af[30][30];
bool visit[30][30];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, M;

bool bfs(int xx, int yy, int num) {
   int tmp = bef[xx][yy];

   queue<pair<int, int>> q;

   bef[xx][yy] = num; //before을 after과 같은 수로 바꾼다.
   visit[xx][yy] = true; //방문 표시
   q.push(make_pair(xx, yy));

   while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
         int nx = x + dx[i];
         int ny = y + dy[i];

         //범위를 벗어나거나 이미 방문했거나 숫자가 다른 경우.
         if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
         if (visit[nx][ny] || bef[nx][ny] != tmp) continue;

         bef[nx][ny] = num;
         visit[nx][ny] = true;
         q.push(make_pair(nx, ny));
      }
   }

   for (int i = 0; i < N; i++){
      for (int j = 0; j < M; j++) {
         if (bef[i][j] != af[i][j])
            return false;
      }   
   }
   return true;
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> N >> M;

   for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
         cin >> bef[i][j];

   for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
         cin >> af[i][j];

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         if (bef[i][j] != af[i][j]) {
            bool ans = bfs(i, j, af[i][j]);

            if (ans) cout << "YES";
            else cout << "NO";

            return 0;
         }
      }
   }
   cout << "YES";
}
