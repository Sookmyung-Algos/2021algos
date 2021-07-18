#include <iostream>
using namespace std;

int d[1000001];

int solve(int n) {
   if (n == 1) 
      return 0;
   if (d[n] > 0)
      return d[n];

   d[n] = solve(n - 1) + 1;

   if (n % 2 == 0) {
      int num = solve(n / 2) + 1;
      if (d[n] > num) 
         d[n] = num;
   }

   if (n % 3 == 0) {
      int num = solve(n / 3) + 1;
      if (d[n] > num) 
         d[n] = num;
   }
   return d[n];
}

int main() {
   int a; 
   cin >> a;
   cout << solve(a);
   return 0;
}
