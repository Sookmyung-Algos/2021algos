#include <iostream>
#include <vector>
using namespace std;

int n, cnt = 0;

int arr[1001][1001];
vector<int> v[1001];

void dfs(int cur) {
   while (!v[cur].empty()) {
      if (arr[cur][v[cur].back()]) {
         arr[cur][v[cur].back()]--;
         arr[v[cur].back()][cur]--;
         dfs(v[cur].back());
      }
      else v[cur].pop_back();
   }
   cout << cur + 1 << ' ';
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> n;
   for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < n; j++) {
         cin >> arr[i][j];
         if (arr[i][j]) v[i].push_back(j);
         sum += arr[i][j];
      }
      if (sum % 2) {
         cout << "-1\n";
         return 0;
      }
   }

   dfs(0);
   cout << '\n';
   return 0;
}
