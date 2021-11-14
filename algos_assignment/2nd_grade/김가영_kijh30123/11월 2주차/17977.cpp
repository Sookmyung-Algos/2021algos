#include <iostream>
using namespace std;

int n;
long long dp[1000000];

int main() {

   cin >> n;
   dp[3] = 0;
   dp[4] = 1;

   for (int i = 5; i <= n; i++) {
      if (i % 2 == 0) {
         dp[i] = dp[i / 2] + 2;
      }
      else {
         dp[i] = dp[(i + 1) / 2] + 2;
      }
   }
   
   cout << dp[n];

   return 0;
}
