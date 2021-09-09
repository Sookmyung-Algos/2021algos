#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

bool check[5000] = { false };
int ans[5000] = { -1, };
int n, k;

int main() {

   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   cin >> n >> k;
   int start = 1, end = n;
   int point = 1;
   memset(ans, -1, sizeof(ans)); //메모리를 모두 -1로 변경
   //오름차순에 넣어주기 위해서
   while (k) {
      if (k >= end - 1) { //남은 만들 쌍이 최대로 만들수있는 그렇고 그런 쌍보다 크다,
         k -= end - 1;
         ans[point++] = end; //최고쌍을 넣어줌
         check[end] = true;
      }
      end--;
   }
   int a = 1;
   for (int i = 1; i <= n; ++i) { //빈곳에 오름차순으로 넣어줌
      if (ans[i] != -1) continue; //이를위해 memset사용
      while (check[a]) ++a;
      ans[i] = a++;
   }
   for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
   }
   return 0;
}
