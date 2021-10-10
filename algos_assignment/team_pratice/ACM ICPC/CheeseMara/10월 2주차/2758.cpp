#include <iostream>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
#define endl '\n'
#define vll vector<long long>
using namespace std;
int main() {
   ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t, n, m;
   cin >> t;
   while (t--) {
      cin >> n >> m;
      vector<vll>dp(n + 1, vll(m + 1));
      for (int i = 0; i <= m; i++) dp[0][i] = 1;
      for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j / 2] + dp[i][j - 1];
         }
      }
      cout << dp[n][m] << endl;
   }
   return 0;
}
