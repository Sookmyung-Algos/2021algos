#include <iostream>
using namespace std;

int N;
int arr[1001]={0,};
int dp[1001]={0,};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    /* 입력 */
    cin >> N;
    for (int i=0;i<N;i++) cin >> arr[i];

    /* LIS 알고리즘 (dp이용) */
    int res=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<i;j++){
            if (arr[i] > arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
                res = max(dp[i],res);
            }
        }
    }
    cout << res+1;
    return 0;
}
