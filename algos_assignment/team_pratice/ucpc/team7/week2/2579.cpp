#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(int argc, const char * argv[]) {
    int N, tmp;
    vector<int> v;
    int dp[301] = {0, };
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        v.push_back(tmp);
        dp[i] = 0;
    }
    
    dp[0] = v[0];
    dp[1] = dp[0] + v[1];
    dp[2] = max(dp[0] + v[2], v[1] + v[2]);
    
    for (int i = 3; i < N; i++) {
        dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
    }
    
    cout << dp[N - 1] << '\n';
    
    return 0;
}
