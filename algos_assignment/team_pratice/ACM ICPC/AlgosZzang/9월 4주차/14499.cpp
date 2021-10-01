// 14499
#include <iostream>
#include <vector>
using namespace std;

int MAP[20][20];
int dice[7];
vector<int> cmd;

int dx[4] = { 0, 0, -1, 1 }; // 동 서 북 남 -- 세로(x), 가로(y)
int dy[4] = { 1, -1, 0, 0 };

void roll(int d) {
   int d1, d2, d3, d4, d5, d6;
   d1 = dice[1], d2 = dice[2], d3 = dice[3];
   d4 = dice[4], d5 = dice[5], d6 = dice[6];

   if (d == 0) { // 동
      dice[1] = d4;
      dice[4] = d6;
      dice[6] = d3;
      dice[3] = d1;
   }
   else if (d == 1) { // 서
      dice[1] = d3;
      dice[3] = d6;
      dice[6] = d4;
      dice[4] = d1;
   }
   else if (d == 2) { // 북
      dice[1] = d5;
      dice[5] = d6;
      dice[6] = d2;
      dice[2] = d1;
   }
   else { // 남
      dice[1] = d2;
      dice[2] = d6;
      dice[6] = d5;
      dice[5] = d1;
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int n, m, x, y, k;
   cin >> n >> m >> x >> y >> k;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> MAP[i][j];
      }
   }
   for (int i = 0; i < k; i++) {
      int c; cin >> c;
      cmd.push_back(c - 1);
   }

   for (int i = 0; i < cmd.size(); i++) {
      int nx = x + dx[cmd[i]];
      int ny = y + dy[cmd[i]];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      
      roll(cmd[i]);

      if (MAP[nx][ny] == 0) MAP[nx][ny] = dice[6];
      else {
         dice[6] = MAP[nx][ny];
         MAP[nx][ny] = 0;
      }

      cout << dice[1] << "\n";

      x = nx;
      y = ny;
   }
}
