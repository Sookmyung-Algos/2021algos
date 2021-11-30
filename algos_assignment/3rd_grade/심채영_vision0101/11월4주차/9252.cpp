#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000 + 1;
int lcs[1001][1001];
string str1, str2;
int str1_len, str2_len;
int i, j;
string ans = "";

int main() {
  cin >> str1 >> str2;
  str1_len = str1.length();
  str2_len = str2.length();

  for(i = 1; i <= str1_len; i++) {
    for(j = 1; j <= str2_len; j++) {
      if(str1[i - 1] == str2[j - 1]) {
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
      }
      else {
        if(lcs[i - 1][j] < lcs[i][j - 1]) {
          lcs[i][j] = lcs[i][j - 1];
        }
        else {
          lcs[i][j] = lcs[i -1][j];
        }
      }
    }
  }

  i = str1_len - 1;
  j = str2_len - 1;

  while(i >= 0 && j >= 0) {
    if(lcs[i + 1][j + 1] == lcs[i][j + 1])
      i--;
    else if(lcs[i + 1][j + 1] == lcs[i + 1][j])
      j--;
    else {
      ans += str1[i];
      i--;
      j--;
    }
  }
  cout << lcs[str1_len][str2_len] << '\n';
  for(i = (int)ans.size() - 1; i >= 0; i--)
    cout << ans[i];


} 
