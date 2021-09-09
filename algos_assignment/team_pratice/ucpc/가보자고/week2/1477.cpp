#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm> 
#include <queue>
#include <math.h>
#define MAX 20001
using namespace std;
int arr[104];
int gap[104];
int main() {
   cin.tie(0);
   cout.tie(0);
   ios_base::sync_with_stdio(false);
   
   int n, m, l;
   cin >> n >> m >> l;
   arr[0] = 0;
   arr[n+1] = l;
   for (int i = 1; i <= n; i++) {
      cin >> arr[i];
   }
   sort(arr, arr + n+1);

   for (int i = 0; i <= n; i++) {
      gap[i] = arr[i + 1] - arr[i];
   }

   sort(gap, gap + n+1 ,greater <int> ());

   int result, dis;
   int left = 1, right = gap[0];
   int hucnt = 0;//휴게소 개수
   while (left <= right) {
      int mid = (left + right) / 2;
      hucnt = 0;
      dis = 0;

      for (int i = 0; i < n + 1; i++) {
         int a = gap[i] / mid;

         if (a == 0) continue;
         if (gap[i] % mid == 0) hucnt += (a-1);
         else {
            hucnt += a;
            
         }
         
      }

      if (hucnt > m) left = mid + 1;
      else {
          result = mid;
         right = mid - 1;
      }
   }
   cout << result;
   return 0;

} 
