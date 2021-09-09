#include <iostream>
#include <algorithm>

using namespace std;
int lesson[100001];

int main() {
   ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

   int n, m;
   int l = 1, r = 0, mid;

   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      cin >> lesson[i];
      r += lesson[i]; // 레슨 길이 총합
        l=max(l,lesson[i]); // 레슨 길이 중 최대
   }

   while (l <= r) {
      mid = (l + r) / 2; // 블루레이 크기 가정하는 mid
      int temp = 0, cnt = 0; // 레슨 길이 합 저장하는 temp, 블루레이 개수 저장하는 cnt

      for (int i = 0; i < n; i++) {
         if (temp + lesson[i]> mid) {
            temp = 0;
            cnt++;
         }
         temp += lesson[i]; //* temp=0 의 영향으로 위치 고정됨
      }

      if (temp != 0)   cnt++; // mid보다 작아서 cnt을 1 증가시키지 못한 경우

      if (cnt <= m)
         r = mid - 1;
      else
         l = mid + 1;
   }
   cout << l; // 블루레이 크기 중 최소
   return 0;
}
