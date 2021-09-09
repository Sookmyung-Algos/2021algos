#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int L, C;

void dfs(string s, vector<char> alpha, int len, int n) {
   if (len == L) {
      int vow = 0, con = 0;
      for (int i = 0; i < L; i++) {
         if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') vow++;
         else con++;
      }
      if (vow >= 1 && con >= 2)
         cout << s << "\n";
      return;
   }
   for (int i = n+1; i <= C - L + len; i++)
      dfs(s+alpha[i], alpha, len + 1, i);
}

int main() {
   cin >> L >> C;

   vector<char> alpha(C);
   for (int i = 0; i < C; i++)
      cin >> alpha[i];

   sort(alpha.begin(), alpha.end());

   string str = "";

   for (int i = 0; i <= C - L; i++)
      dfs(str+alpha[i], alpha, 1, i);
   
   return 0;
}
