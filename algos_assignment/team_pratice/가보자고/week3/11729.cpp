#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n,int start, int mid, int end) {
   if (n == 1)
      cout << start << " " << end << '\n';
   else {
      hanoi(n - 1, start, end, mid);   // start자리의 기둥 n-1개를 mid자리로
      cout << start << " " << end << '\n';
      hanoi(n - 1, mid, start, end);   // mid자리의 기둥 n-1개를 end자리로
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   int num;

   cin >> num;
   cout << (int)pow(2, num) - 1<<'\n';   //pow 반환값 실수이므로 (int)필요함
   hanoi(num, 1, 2, 3);

   return 0;
}
