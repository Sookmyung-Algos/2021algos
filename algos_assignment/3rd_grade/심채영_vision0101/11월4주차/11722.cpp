#include <iostream>
using namespace std;

const int MAX = 1000 + 1;

int main() {
  int n;
  int a[MAX];
  int d[MAX] = {0,};
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(a[j] > a[i]) {
        if(d[i] < d[j]) {
          d[i] = d[j];
          //max(d[i], d[j] + 1);
        }
      }
    }
    d[i]++;
  }
  int ans = 0;

  for(int i = 0; i < n; i++) {
    if(ans < d[i]) {
      ans = d[i];
    }
  }

  cout << ans;
} 


