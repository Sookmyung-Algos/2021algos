#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int n;
   cin >> n;
   int dp[50001];
   for (int i = 0;i <= 50000;i++) dp[i] = i;
   
   for (int i = 1;i <= n;i++) {
      for (int j = 1;j*j<=i;j++) {
         dp[i] = min(dp[i], 1 + dp[i - j * j]);
      }
   }
   cout << dp[n];
}