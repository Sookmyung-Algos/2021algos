#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);
   int n;
   cin >> n;

   vector<pair<int, int>> v;
   for (int i = 0; i < n; i++) {
      pair<int, int> a, b;
      cin >> a.first >> a.second >> b.first >> b.second;

      v.push_back({ a.first * 100 + a.second, b.first * 100 + b.second });
      //날짜를 숫자화시키고 벡터에 저장
   }
   sort(v.begin(), v.end());

   int idx = -1;
   int temp = 0;
   int ans = 0;

   for (int i = 301; i <= 1130 && idx < n; i = temp) {
      bool flag = false;
      idx++;

      for (int j = idx; j < v.size(); j++) {
         if (v[j].first > i) break; // 넣으면 앞이 비게 되므로
         if (temp < v[j].second) { //기간을 연장할 수 있다면
            temp = v[j].second;
            idx = j;
            flag = true;
         }
      }
      if (flag) ans++; //넣는다
      else { //넣지 않으면 불가능하므로 0
         cout << 0 << "\n";
         return 0;
      }
   }
   cout << ans; //빠져나오면 결과출력
   return 0;
}
