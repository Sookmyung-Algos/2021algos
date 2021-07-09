#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;

char p[100001];

int main() {
   int T; 
   scanf("%d", &T);

   while (T--) {
      int n, x, c; bool re = false, error = false;
      deque <int> dq;

      scanf("%s", &p);
      scanf("%d\n", &n);
      scanf("%c", &c); // '['
      if (n) {
         for (int i = 0; i < n; i++) {
            scanf("%d%c", &x, &c);
            dq.push_back(x);
         }
      }
      else
         scanf("%c%c", &c, &c);

      for (int i = 0; i < strlen(p); i++) {
         if (p[i] == 'R')
            re = !re;
         else {
            if (dq.empty()) {
               error = true;
               break;
            }
            if (re) dq.pop_back();
            else dq.pop_front();
         }
      }

      if (!dq.empty() || !error) {
         printf("[");
         if (re) {
            while (!dq.empty()) {
               printf("%d", dq.back());
               if (dq.size() > 1) printf(",");
               dq.pop_back();
            }
            printf("]\n");
         }
         else {
            while (!dq.empty()) {
               printf("%d", dq.front());
               if (dq.size() > 1) printf(",");
               dq.pop_front();
            }
            printf("]\n");
         }
      }
      else printf("error\n");
   }
}
