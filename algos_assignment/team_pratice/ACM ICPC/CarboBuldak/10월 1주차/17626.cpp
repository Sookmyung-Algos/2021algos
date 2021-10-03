#include <iostream>
#include <algorithm>

using namespace std;
int dp[50001];

int main(int argc, const char * argv[]) {
    dp[0] = 0; dp[1] = 1;
    int N;
    cin >> N;
    
    for (int i = 2; i < N + 1; i++) {
        dp[i] = 999999;
    }
    
    for (int i = 2; i < N + 1; i++) {
        for (int j = 1; j < i + 1; j++) {
            if (i < j * j) break;
            if (i == j * j) dp[i] = 1;
            if (i > j * j) dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }
    
    cout << dp[N] << '\n';
    return 0;
}
