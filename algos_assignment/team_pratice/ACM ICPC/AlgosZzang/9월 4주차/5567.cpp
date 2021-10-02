#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm> 
#include <cstring>
#include <math.h>
#include <queue>
#define MAX 1000001
using namespace std;
int n, m;
int map1[502][502];
int friendL[502];
int cnt;
void dfs(int d,int level) {
   if (level == 2) {
      return;
   }
   for (int i = 1; i <= n; i++) {
      if (map1[d][i] == 1) {
         if (friendL[i] == 0 &&i!=1) {
            friendL[i] = 1;
            cnt++;
         }

         dfs(i, level + 1);
      }
   }
}
int main() {
   
   cin.tie(0);
   cout.tie(0);
   ios_base::sync_with_stdio(false);
   


   cin >> n >> m;

   for (int i = 1; i <= m; i++) {
      int a, b;
      cin >> a >> b;
      map1[a][b] = 1;
      map1[b][a] = 1;
   }

   dfs(1,0);
   cout << cnt;
   return 0;

}
