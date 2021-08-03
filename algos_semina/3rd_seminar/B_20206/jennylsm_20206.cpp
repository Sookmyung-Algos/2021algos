#include <iostream>
#include <vector>
using namespace std;

int main() {
   int a, b, c;
   cin >> a >> b >> c;
   int x1, x2, y1, y2;
   cin >> x1 >> x2 >> y1 >> y2;
   vector<pair<int, int>> v;
   v.push_back({ x1,y1 });
   v.push_back({ x1,y2 });
   v.push_back({ x2,y1 });
   v.push_back({ x2,y2 });
   int p = 0, q = 0;
   for (int i = 0; i < v.size(); i++) {
      if (v[i].first * a + v[i].second * b <= -c) p++;
      if (v[i].first * a + v[i].second * b >= -c) q++;
   }
   if (p == 4 || q == 4) cout << "Lucky" << endl;
   else cout << "Poor" << endl;
   return 0;
}
