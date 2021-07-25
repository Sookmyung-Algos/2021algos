#include <iostream>
using namespace std;

int main() {
   int N;
   cin >> N;

   int h, sum = 0, n = 0;
   for (int i = 0; i < N; i++) {
      cin >> h;
      sum += h;
      n += h / 2;
   }

   if (sum % 3 == 0 && n >= sum / 3) cout << "YES";
   else cout << "NO";
}
