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

int arr[100001];
int main() {
   cin.tie(0);
   cout.tie(0);
   ios_base::sync_with_stdio(false);
   
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }

   int minn = 21e8;
   int e = 0, s = 0;
   int total = 0;
   total += arr[0];
   pair<int, int> vect;

   for (int i = 0; i < n; i++) {
      int a = arr[i];
      int left = i + 1, right = n - 1;
      while (left <= right) {
         int mid = (left + right) / 2;
         int b = abs(a + arr[mid]);
         if (b < minn) {
            minn = b;
            vect.first = arr[i];
            vect.second = arr[mid];
         }

         if (abs(arr[i]) < abs(arr[mid])) right = mid - 1;
         else left = mid + 1;
      }
   }
   cout << vect.first << " " << vect.second;
   return 0;

}
