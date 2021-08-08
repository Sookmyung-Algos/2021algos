#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, h;

int map[10][10];
int home[2]; // [0]: y좌표 [1]: x좌표
vector<pair<int, int>> milk;
int visit[10][10];
int ans;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int calc(int y1, int x1, int y2, int x2) {
   return abs(x1 - x2) + abs(y1 - y2);
}

void find_mincho(int y, int x, int hp, int cnt) {
   if (calc(y, x, home[0], home[1]) <= hp) {
      ans = max(ans, cnt);
   }
   
   for (int i = 0; i < milk.size(); i++) {
      if (visit[milk[i].first][milk[i].second]) continue;

      int temp = calc(y, x, milk[i].first, milk[i].second);
      if (temp > hp) continue;
      
      visit[milk[i].first][milk[i].second] = 1;
      find_mincho(milk[i].first, milk[i].second, hp + h - temp, cnt + 1);
      visit[milk[i].first][milk[i].second] = 0;
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> n >> m >> h;

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cin >> map[i][j];
         if (map[i][j] == 1) home[0] = i, home[1] = j;
         else if (map[i][j] == 2) milk.push_back({ i,j });
      }
   }

   find_mincho(home[0], home[1], m, 0);
   cout << ans;
}
