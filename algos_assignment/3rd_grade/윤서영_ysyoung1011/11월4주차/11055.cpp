#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, a[1001], dp[1001]={0,};
vector<int> v;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) {
                if(dp[i] < dp[j]) {
                    dp[i] = dp[j];
                }
            }
        }
        dp[i] += a[i];
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(ans < dp[i]){
            ans = dp[i];
        }
    }
    cout << ans;
}
