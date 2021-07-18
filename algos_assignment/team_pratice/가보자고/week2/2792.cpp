#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   int n, m; // n:학생 수, m:색상 수
   cin >> n >> m;

   vector<int> color(m);  // 보석
   for (int i = 0; i < m; i++) {
      cin >> color[i];
   }
   int right = *max_element(color.begin(), color.end());  // 어떤 색상의 보석의 최대 개수(최대 질투심)
   int left = 1;  // 못 받는 학생 존재하기 때문에(최소 질투심)
   /*
      left = 0이면 런타임에러(DivisionByZero)
   */
   while (left <= right) {
      int numOfPeople = 0;  // 보석 받는 학생 수
      int mid = (left + right) / 2;  // mid가 최소 질투심이라고 가정
      for (int i = 0; i < m; i++) {
         int a = color[i] / mid;  // i번째 색 보석을 mid개 받는 학생 수
         int b = color[i] % mid;  // 위 학생들이 mid개 받으면 남는 보석 개수 
         numOfPeople += a;
         if (b != 0)
            numOfPeople++;
      }
      if (numOfPeople > n)
         left = mid + 1;
      else
         right = mid - 1;
   }
   cout << left;
   return 0;
}
