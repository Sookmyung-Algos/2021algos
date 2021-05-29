#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,w,v,k;
    cin >> n >> k;
    
    for (int i=1;i<=n;i++){
        cin >> w >> v;
        
        for (int j=1;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            if (j-w>=0){ // 물건을 담을 수 있는 경우
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w]+v);
            }
        }
    }
    cout << dp[n][k] << '\n';
    return 0;
}
