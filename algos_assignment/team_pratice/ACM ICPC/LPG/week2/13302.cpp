#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int d[101][101];
bool rest[101];// 수영이가 쉬는날

int resort(int day, int coupon) { // 현재 날짜와 쿠폰 개수
   if (day >= n + 1) return 0;

   int &ret = d[day][coupon];
   if (ret != -1) return ret;

   if (rest[day]) ret = resort(day + 1, coupon);
   else {
      ret = 0x3f3f3f3f;
      ret = min(ret, resort(day + 1, coupon) + 10000);
      ret = min(ret, resort(day + 3, coupon + 1) + 25000);
      ret = min(ret, resort(day + 5, coupon + 2) + 37000);

      if (coupon >= 3) {
         ret = min(ret, resort(day + 1, coupon - 3));
      }
   }
   return ret;
}
int main() {
   cin >> n >> m;
   while (m--) {
      int x;
      cin >> x;
      rest[x] = true;
   }
   memset(d, -1, sizeof(d));

   cout << resort(1, 0) << '\n';
}
