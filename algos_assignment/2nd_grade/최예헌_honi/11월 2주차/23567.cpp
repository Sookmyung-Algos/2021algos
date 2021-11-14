#include <iostream>
using namespace std;

int main() {
   cin.tie(0); cout.tie(0);
   ios::sync_with_stdio(false);
   int arr[10001];
   int num[10001]={0,};
   int temp1[10001]={0,};
   int result = 0;

   int n, k;
   cin >> n >> k;
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
      num[arr[i]]++;
   }

   int s = (k < n - k) ? k : n - k;
   int e = (k < n - k) ? n - k : k;

   while (s <= e) {
      int mid = (s + e) / 2;

      int l = 0;
      int r = mid-1;
      int cnt = 0;

      while (r < n) {
         bool flag = true;      //가능한지

         int temp2[10001] = { 0, };      //더블 레인보우
         
         for (int i = 1; i <= k; i++) {   //제외부분
            temp1[i] = num[i];
         }

         for (int i = l; i <= r; i++) {
            temp2[arr[i]]++;
            temp1[arr[i]]--;
         }

         for (int i = 1; i <= k; i++) {
            if (temp1[i] == 0 || temp2[i] == 0) {
               flag = false;
               break;

            }
         }
         if (flag) {
            cnt++;
         }
         l++; r++;
      }
      if (cnt > 0) {
         result = mid;
         e = mid - 1;
      }
      else
         s = mid + 1;
   }
   cout << result;
}
