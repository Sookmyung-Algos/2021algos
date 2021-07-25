#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, t, num;
const long long INF = 99999999999;

long long domination() {
   v.push_back(0);

   int index = 0, cnt;
   for (int j = 1; j < v.size(); j++) {
      if (v[j - 1] != v[j] || j == v.size() - 1) {
         cnt = j - index;
         if (cnt > t / 2) return v[index];
         index = j;
      }
   }
   cout << "SKJKGW\n";
   return INF;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> t;
      for (int j = 0; j < t; j++) {
         cin >> num;
         v.push_back(num);
      }
      sort(v.begin(), v.end());
      long long ans = domination();
      if (ans != INF) cout << ans << "\n";
      v.clear();
   }
}
