#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[51];
int visit[51];
int n, cnt, ans = 0;

void dfs(int cur, int depth) {
   if (depth == 2) return;

   for (int i = 0; i < v[cur].size(); i++) {
      int next = v[cur][i];
      if (visit[next]) dfs(next, depth + 1);
      else {
         visit[next] = 1;
         cnt++;
         dfs(next, depth + 1);
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> n;
   char c;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cin >> c;
         if (c == 'Y') v[i].push_back(j);
      }
   }

   for (int i = 0; i < n; i++) {
      memset(visit, 0, sizeof(visit));
      cnt = 0;
      visit[i] = 1;
      dfs(i, 0);
      ans = max(ans, cnt);
   }

   cout << ans << '\n';

   return 0;
}
