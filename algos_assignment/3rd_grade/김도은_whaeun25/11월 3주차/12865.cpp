#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 110

using namespace std;

int n, k;

int w[MAX];
int v[MAX];
int dp[MAX][100010];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<= k; j++){
            if (j >= w[i]){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    cout << dp[n][k];
    
    
}
