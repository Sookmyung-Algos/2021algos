#include<iostream>
using namespace std;
int a[10000];
int d[10000]; 
int main() {
   int n; // 포도주 잔의 개수
   cin >> n; 
   for (int i = 1; i <= n; i++) {
      cin >> a[i]; // 포도주 잔에 들어있는 포도주의 양
   }
   d[1] = a[1];
   d[2] = a[1] + a[2];
   for (int i = 3; i <= n; i++) {
      d[i] = d[i - 1];
      if (d[i] < d[i - 2] + a[i]) {
         d[i] = d[i - 2] + a[i];
      }
      if (d[i] < d[i - 3] + a[i - 1] + a[i]) {
         d[i] = d[i - 3] + a[i - 1] + a[i];
      }
   }
   cout << d[n] << '\n';
}
