#include <iostream>
#include <stdio.h>
#include <stdlib.h>
 
#define MAX 1000000

using namespace std; 
 
long long Dp[MAX + 1];
int init[3] = { 1,2,4 };

void bottomUp(int n) {
    
    Dp[1] = 1;
    Dp[2] = 2;
    Dp[3] = 4;
 
    for (int i = 4; i <= n; i++) {
        Dp[i] = Dp[i - 1] + Dp[i - 2] + Dp[i - 3];
        Dp[i] %= 1000000009;
    }
}
 
int main() {
    int t, n;
    
    bottomUp(MAX);
 
    cin >> t;
   
    while (t--) {
        cin >> n;
        cout << Dp[n] << "\n";
    }
}
