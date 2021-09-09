#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 1001

int M, N;
int day;
int box[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

queue <pair<pair<int, int>, int>> q;

void BFS() {
   while (!q.empty()) {
      int x = q.front().first.first; //x 좌표
      int y = q.front().first.second; //y 좌표
      day = q.front().second; //일 수

      q.pop();

      for (int i = 0; i < 4; i++) {
         int nx = x + dx[i];
         int ny = y + dy[i];

         if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
         if (box[nx][ny] == 0 && !visit[nx][ny]) {
            visit[nx][ny] = true;
            q.push(make_pair(make_pair(nx, ny), day + 1)); //하루가 지남
         }
      }
   }
}

void unripe() {
   for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
         if (box[i][j] == 0 && !visit[i][j]) {
            day = -1;
            break;
         }
      }
   }
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> N >> M;

   for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
         cin >> box[i][j];
         if (box[i][j] == 1) {
            visit[i][j] = true;
            q.push(make_pair(make_pair(i, j), 0)); //{{x, y}, day}와 같이 pair로 묶어 저장
         }
      }
   }

   BFS();
   unripe();

   cout << day;
   return 0;
}
