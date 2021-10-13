#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K;
int num[11];
int where[11];
bool chk[11];
int res = 98787987;
vector <int> node[11];

void dfs(int n, int k) {
   for (int i = 0; i<node[n].size(); i++) {
      if (chk[node[n][i]] == false && where[node[n][i]] == k) {
         chk[node[n][i]] = true;
         dfs(node[n][i], k);
      }
   }
}

bool chking() {
   for (int i = 1; i <= N; i++) {
      if (where[i] == 1) {
         chk[i] = true;
         dfs(i, 1);
         break;
      }
   }

   for (int i = 1; i <= N; i++) {
      if (where[i] == 0) {
         chk[i] = true;
         dfs(i, 0);
         break;
      }
   }

   for (int i = 1; i <= N; i++) {
      if (chk[i] == false)   return false;
   }
   return true;
}

void combi(int cnt) {
   if (cnt == N) {
      memset(chk, false, sizeof(chk));
      if (chking()) {
         int sum1 = 0, sum2 = 0;
         for (int i = 1; i <= N; i++) {
            if (where[i] == 1) {
               sum1 += num[i];
            }
            else {
               sum2 += num[i];
            }
         }
         int result = abs(sum1 - sum2);
         if (res>result)  res = result;
      }
      return;
   }
   where[cnt + 1] = 1;
   combi(cnt + 1);
   where[cnt + 1] = 0;
   combi(cnt + 1);
}

int main() {
   cin >> N;

   for (int i = 1; i <= N; i++) {
      cin >> num[i];
   }

   for (int i = 1; i <= N; i++) {
      cin >> K;
      for (int j = 0; j<K; j++) {
         int temp;
         cin >> temp;
         node[i].push_back(temp);
      }
   }

   combi(0);
   if (res == 98787987)   res = -1;
   cout << res << "\n";

   return 0;
}
