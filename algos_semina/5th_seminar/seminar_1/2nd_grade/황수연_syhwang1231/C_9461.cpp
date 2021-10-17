#include <iostream>
#define MAX 101
using namespace std;

long long dp[MAX];
int t,n;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    
    for(int i=0;i<t;i++){
        cin >> n;
        if(n==1 || n==2 || n==3){  // n이 1, 2, 3인 경우 미리 처리
            cout << 1 << "\n";
            continue;
        }
        
        for(int k=4;k<=n;k++){
            dp[k] = dp[k-2]+dp[k-3];  // 점화식
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
