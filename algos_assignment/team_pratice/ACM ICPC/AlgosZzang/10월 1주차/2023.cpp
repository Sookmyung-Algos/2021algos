#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm> 
#include <cstring>
#include <math.h>
#include <queue>
#define MAX 1000001

using namespace std;
bool prime(int n) {
   if (n <= 2) return false;
   for (int i = 2; i <n; i++) {
      if (n % i == 0) return false;
   }
   return true;
}
void dfs(int a, int n) {
   if (n == 0) cout << a << "\n";

   for (int i = 1; i <= 9; i += 2) {
      if (prime(i + 10 * a)) {
         dfs(i + 10 * a, n - 1);
      }


   }
}
int main() {
   
   cin.tie(0);
   cout.tie(0);
   ios_base::sync_with_stdio(false);

   int n;
   cin >> n;
   int arr[4] = { 2,3,5,7 };


   for (int i = 0; i < 4; i++) {
      dfs(arr[i], n - 1);
   }

   
   return 0;

}
