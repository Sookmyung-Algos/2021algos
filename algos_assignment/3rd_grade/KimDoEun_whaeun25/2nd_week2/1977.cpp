#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int dp[10000];

int main(){
    int m, n;
    int sum = 0, ans = 10000;

    cin >> m >> n;

    for(int i=1; i<=n; i++){
        dp[i] = i*i;
    }

    for(int i=1; i<=n; i++){
        if(m <= dp[i] && dp[i] <= n){
            sum += dp[i];
            ans = min(ans, dp[i]);
        }
    }

    if(sum == 0){
        cout << "-1\n";
    } else{
        cout << sum << "\n";
        cout << ans << "\n";
    }

    return 0;
}
