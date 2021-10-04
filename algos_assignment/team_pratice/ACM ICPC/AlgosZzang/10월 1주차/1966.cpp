// 1966
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(int a, int b) {
   return a > b;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int T;
   cin >> T;

   int N, doc, imp;
   while (T--) {
      cin >> N >> doc;

      queue<pair<int, int>> q;
      int arr[101];
      for (int i = 0; i < N; i++) {
         cin >> imp;
         q.push({ imp, i });
         arr[i] = imp;
      }
      sort(arr, arr + N, cmp);

      int cnt = 0;
      while (1) {
         pair<int, int> temp = q.front();
         if (arr[cnt] != temp.first) {
            q.push({ temp.first, temp.second });
            q.pop();
         }
         else {
            cnt++;
            q.pop();

            if (temp.second == doc) {
               cout << cnt << "\n";
               break;
            }
         }
      }
   }
}
