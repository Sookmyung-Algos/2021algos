#include <iostream>

using namespace std;

int main() {
   int num[5];
  
   for (int i = 0; i < 5; i++) {
      cin >> num[i];
   }
  
   int n = 1;
  
   while (1) {
      int cnt = 0;
     
      for (int i = 0; i < 5; i++) {
         if (n % num[i] == 0)
           cnt++;
      }
      if (cnt >= 3)
        break;
      n++;
   }
   cout << n;
}
