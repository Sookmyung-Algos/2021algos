#include <iostream>
#include <stack>
using namespace std;

int dp[41][41];

stack<char> s;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   string a, b;
   cin >> a >> b;

   int as = a.size(),
      bs = b.size();

   for (int i = 1; i <= as; i++) {
      for (int j = 1; j <= bs; j++) {
         if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
         else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
   }

   while (as && bs) {
      if (a[as - 1] == b[bs - 1]) {
         s.push(a[as - 1]);
         as--; bs--;
      }
      else {
         if (dp[as - 1][bs] == dp[as][bs]) as--;
         else bs--;
      }
   }

   while (!s.empty()) {
      cout << s.top();
      s.pop();
   }

   cout << '\n';

   return 0;
}
