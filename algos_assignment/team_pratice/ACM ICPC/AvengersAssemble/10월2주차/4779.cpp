#include <iostream>
#include <cmath>
using namespace std;

void solve(int x, int sz) {
   if (sz == 1) {
      cout << '-';
      return;
   }
   sz /= 3;
   solve(x, sz);
   for (int i = 0;i < sz;i++) cout << ' ';
   solve(x + sz * 2, sz);
}

int main() {
   int n;
   while (cin>>n) {
      n = pow(3,n);
      solve(0, n);
      cout << '\n';
   }
   
}