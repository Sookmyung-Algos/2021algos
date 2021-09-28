#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    int v[10001], dp[10001];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    dp[1] = v[1];
    dp[2] = dp[1] + v[2];
    for (int i = 3; i <= n; i++){
        dp[i] = max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]);
        dp[i] = max(dp[i - 1], dp[i]);
    }
    cout << dp[n] << '\n';
    return 0;
}
