#include<iostream>
#include<algorithm>
using namespace std;
int dp[1001];
int n;
int arr[10001];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    // dp[3] = arr[1]+arr[1]+arr[1] => arr[1] + dp[2],
    //    arr[2]+arr[1] => arr[2] + dp[1],
    // arr[3] => arr[3] + dp[0]
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], arr[j] + dp[i - j]);
        }
    }
    cout << dp[n];
}
