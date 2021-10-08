#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int n, m, ans = 200001;  //최대가 200000이라고 했으므로 처음에 200001로 초기화
   vector<int> v;
   cin >> n;
   for (int i = 0; i < 2*n; i++) {
      cin >> m;
      v.push_back(m); //학생들의 역량 벡터에 넣는다
   }
   sort(v.begin(), v.end());
   for (int j = 0; j < 2 * n; j++) ans = min(ans, v[j] + v[2 * n - 1 - j]); //현재의 ans값과 비교하여 반복문을 통해 최소값 업데이트
   cout << ans;
}
