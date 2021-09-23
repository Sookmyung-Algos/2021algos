// 2293 동전1 (Silver 1)
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int n, k;
vector<int> coins;
vector<int> dp;  // i원을 만들 수 있는 경우는 dp[i] 가지 

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    coins.resize(n+1);
    dp.resize(k+1);
    for(int i=1;i<=n;i++)
        cin >> coins[i];
    
    dp[0] = 1;
    for(int i=1;i<=n;i++){  // 경우의 수에 사용할 수 있는 동전은 n가지의 동전들
        for(int j=coins[i];j<=k;j++)  // coins[i]원을 사용해서 j원을 만드는 경우를 계산
            dp[j] += dp[j-coins[i]];
    }
    
    cout << dp[k];
    return 0;
}
