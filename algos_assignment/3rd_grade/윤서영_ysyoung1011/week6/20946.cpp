#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<long long> v;

int main() {
   long long num; // 입력받을 숫자
   long long k = 2; // 2부터 1씩 증가하는 숫자

   cin >> num;

   for (int i = 2; i <= sqrt(num); i++) {
      if (num%i == 0) {
         num /= i;
         v.push_back(i);
         i -= 1;
      }
   }
   if (num > 1)   v.push_back(num);

   if (v.size() < 4) {
      if (v.size() == 2) {
         cout << v[0] * v[1];
         return 0;
      }
      if (v.size() == 3) {
         cout << v[0] * v[1] *v[2];
         return 0;
      }
      cout << -1;
      return 0;
   }
   long long tmp = 1;
   for (long long i = 0;i < v.size();i++) {
      tmp *= v[i];
      if (i % 2 == 1) {
         if (i == v.size() - 2) {
            tmp *= v[v.size() - 1];
            cout << tmp << " ";
            return 0;
         }
         cout << tmp << " ";
         tmp = 1;
      }
   }
   return 0;
}
