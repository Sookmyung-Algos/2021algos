#include<iostream>
#include <cmath>
using namespace std;

int main() {

   double h1, h2, h3;
   cin >> h1 >> h2 >> h3;

   double x = 1 / h1;
   double y = 1 / h2;
   double z = 1 / h3;
   
   double tmp = sqrt((x + y + z) * (y + z - x) * (x + z - y) * (x + y - z));

   double a = 2 * x*  h1 / tmp;

   double ans = a / 2;

   cout.precision(10);
   cout << ans;

   return 0;   
}
