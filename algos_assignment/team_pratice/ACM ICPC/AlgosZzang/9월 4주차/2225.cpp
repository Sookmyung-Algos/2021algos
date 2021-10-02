// 2225 합분해
#include <iostream>
using namespace std;

int dp[201][201];

int main(){
    int n, k;
    cin >> n >> k;
    
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
        dp[1][i]=1;
    }
        
    for(int i=2;i<=k;i++){
        for(int j=0;j<=n;j++){
            for(int l=0;l<=j;l++){
                dp[i][j]=(dp[i][j]+dp[i-1][j-l])%1000000000;
            }
        }
    }
    cout << dp[k][n];
}
