// 11060번 점프점프
// DP
#include <iostream>
#define INF 987654321
using namespace std;

int dp[10001] = {0,};
int arr[10001] = {0,};
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    /* 입력 */
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
        dp[i] = INF;
    }
 
    /* 값 갱신 */
    dp[0] = 0;
    for (int i=0;i<N;i++) {
        for (int j=1;j<=arr[i]; j++) {
            if (i+j >= N) dp[i+j] = dp[i] + 1;
            else dp[i+j] = min(dp[i+j], dp[i] + 1);
        }
    }
    /* 출력 */
    if (dp[N - 1] > 1001) cout << -1 << '\n';
    else cout << dp[N - 1] << '\n';
}
