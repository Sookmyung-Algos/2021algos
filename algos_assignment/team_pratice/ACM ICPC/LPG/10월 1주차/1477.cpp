#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   int n, m, l;
   cin >> n >> m >> l;
   vector <int> v;
   v.push_back(0);
   for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      v.push_back(a);
   }
   v.push_back(l);
   sort(v.begin(), v.end());
   int left = 0, right = l, mid;
   while (left <= right) {
      mid = (left + right) / 2;
      int cnt=0;
      for (int i = 0; i <= n; i++) {
         if (v[i + 1] - v[i] > mid) cnt += (v[i + 1] - v[i] - 1) / mid;
      }
      if (cnt > m) left = mid + 1;
      else right = mid - 1;
   }
   cout << left << endl;
   return 0;
}
