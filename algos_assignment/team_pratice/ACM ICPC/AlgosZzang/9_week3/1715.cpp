// 1715 카드 정렬하기

#include <iostream>
#include <queue>
#include <functional> // greater
using namespace std;

priority_queue<int, vector<int>, greater<int>> q; // 작은 원소부터 pop

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int n; cin >> n;
   for (int i = 0; i < n; i++) {
      int input; cin >> input;
      q.push(input);
   }

   int ans = 0;
   while (q.size() > 1) {
      int a = q.top(); q.pop();
      int b = q.top(); q.pop();
      ans += a + b;
      q.push(a + b);
   }
   cout << ans;
}
