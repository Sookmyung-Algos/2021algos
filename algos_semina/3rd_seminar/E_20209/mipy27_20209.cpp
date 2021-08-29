#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int n, k;
vector<int> v[9];

bool same(vector<int> cube) {
   int temp = cube[0];
   for (int i = 1; i < cube.size(); i++) {
      if (temp != cube[i]) return false;
   }
   return true;
}

int bfs(vector<int> init) {
   queue<vector<int>> q;
   map<vector<int>, int> m;

   m[init] = 0;
   q.push(init);

   while (!q.empty()) {
      vector<int> cur = q.front();
      q.pop();

      int cnt = m[cur];
      if (same(cur)) return cnt;

      for (int i = 1; i <= k; i++) {
         vector<int> next = cur;

         for (int j = 0; j < v[i].size(); j++) { 
            next[v[i][j]] += i;
            if (next[v[i][j]] > 4) next[v[i][j]] %= 5;
         }

         if (m.find(next) == m.end()) {
            m[next] = cnt + 1;
            q.push(next);
         }
      }
   }
   return -1;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> n >> k;

   vector<int> a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }

   for (int i = 1; i <= k; i++) {
      int b_num, b;
      
      cin >> b_num;
      for (int j = 0; j < b_num; j++) {
         cin >> b;
         v[i].push_back(b - 1);
      }
   }
   cout << bfs(a);
}
