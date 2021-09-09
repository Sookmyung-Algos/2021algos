#include <iostream>
#include <queue>
#define MAX 40
using namespace std;

int n;
int cnt = 0;
bool is1[MAX];
bool is2[MAX];
bool is3[MAX];

void solve(int level) {
   if (level == n) {
      cnt++;
      return;
   }
   for (int i = 0; i < n; i++) {
      if (is1[i] || is2[i + level] || is3[level - i + n - 1])
         continue;
      is1[i] = true;
      is2[i + level] = true;
      is3[level - i + n - 1] = true;
      solve(level + 1);
      is1[i] = false;
      is2[i + level] = false;
      is3[level - i + n - 1] = false;
   }
}

int main() {
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

   cin >> n;
   solve(0);
   cout << cnt;
}
