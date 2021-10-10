#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm> 
#include <cstring>
#include <queue>
#define MAX 1000001
using namespace std;
int n;
int mapp1[51];
int mapp2[51];
int cnt = 0;
void plusOne(int start) {
   for (int i = start; i < n; i++) {
      if (mapp2[i] % 2 != 0) {
         mapp2[i]--;
         cnt++;
      }
   }
}
int main() {
   
   cin.tie(0);
   cout.tie(0);
   ios_base::sync_with_stdio(false);

   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> mapp2[i];
   }
   int i;
   bool iszero = true;
   while (true) {
      i = 0;
      iszero = true;
      int flag = 0;
      for (i = 0; i < n; i++) {
         if (mapp2[i]) iszero = false;
         if (mapp2[i] % 2 != 0) {  //2로 안나뉘어떨어지면 1씩 뺌
            mapp2[i]--;
            cnt++;
            flag = 1;
            break;

         }
         
      }
      if (iszero) break;
      if (flag == 0 ) {
         for (int j = 0; j < n; j++) {
            if (mapp2[j] == 0) continue;
            mapp2[j] /= 2;
            
         }
         cnt++;
      }
   }
   cout << cnt;
   return 0;

}
