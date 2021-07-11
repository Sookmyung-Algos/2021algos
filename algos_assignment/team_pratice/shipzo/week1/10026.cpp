#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char arr[101][101];
int visit[101][101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n;

queue<pair<int, int>> q;

void bfs(int i, int j) {
   int x, y, a, b;

   q.push({ i, j });

   while (!q.empty()) {
      x = q.front().first;
      y = q.front().second;
      q.pop();
      for (int k = 0; k < 4; k++) {
         a = x + dx[k];
         b = y + dy[k];
         if (0 <= a && a < n && 0 <= b && b < n
            && !visit[a][b] && arr[x][y] == arr[a][b]) {
            visit[a][b] = 1;
            q.push({ a, b });
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int cnt = 0;

   cin >> n;

   for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (!visit[i][j]) {
            bfs(i, j);
            cnt++;
         }
      }
   }

   cout << cnt << ' ';

   cnt = 0;
   memset(visit, 0, sizeof(visit));

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         if (arr[i][j] == 'G') arr[i][j] = 'R';

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (!visit[i][j]) {
            bfs(i, j);
            cnt++;
         }
      }
   }

   cout << cnt << '\n';

   return 0;
}
