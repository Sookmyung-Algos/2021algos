//  B2133
//
//  n이 짝수일 때만 1x2,2x1의 타일로 채우기 가능 -> n이 홀수면 0
//  점화식: dp[n] = 3*dp[n-2] + 2*dp[n-4] + 2*dp[n-6] +..+ 2*dp[0]

#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    
    int dp[31];
    dp[0] = 1;
    dp[2] = 3;
    
    if(n % 2 == 1) dp[n] = 0;
    else{
        for(int i = 4; i <= n; i += 2){
            dp[i] = 3 * dp[i-2];
            for(int j = 4; j <= i; j += 2){
                dp[i] += 2 * dp[i - j];
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
