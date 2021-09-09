#include <iostream>
#include <set>

using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int map[5][5] = { 0 };
set<int> nums;

void dfs(int y, int x, int cnt, int num) {
   //길이가 5가 되면 st set에 넣기
   if (cnt == 5) {
      nums.insert(num);
      return;
   }

   for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      //5*5칸 밖으로 나갈 경우
      if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
         continue;

      dfs(ny, nx, cnt + 1, num * 10 + map[ny][nx]);
   }
}

int main(void) {

   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
         cin >> map[i][j];

   for (int i = 0; i < 5; i++) 
      for (int j = 0; j < 5; j++) 
         dfs(i, j, 0, map[i][j]);

   cout << nums.size() << '\n';
   return 0;
}
