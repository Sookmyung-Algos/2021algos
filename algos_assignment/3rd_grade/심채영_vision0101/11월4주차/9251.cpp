#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000 + 1;
int lcs[1001][1001];
string str1, str2;

int main() {
  cin >> str1 >> str2;

  for(int i = 1; i <= str1.length(); i++) {
    for(int j = 1; j <= str2.length(); j++) {
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
  cout << lcs[str1.length()][str2.length()];
} 
