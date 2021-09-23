// B11726
#include <iostream>
using namespace std;

long long dp[1001] = {0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    dp[1]=1; dp[2]=2;

    for (int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
        dp[i] %= 10007;
    }
    cout << dp[n] << endl;
    return 0;
}
