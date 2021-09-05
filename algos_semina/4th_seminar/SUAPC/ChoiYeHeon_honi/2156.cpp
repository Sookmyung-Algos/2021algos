#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    int arr[10001];
    int dp[10001];
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,0,sizeof(dp));
    dp[0]=arr[0];
    dp[1]=dp[0]+arr[1];
    
    for (int i=2;i<n;i++){
        dp[i]=max(max(dp[i-1],dp[i-3]+arr[i-1]+arr[i]),dp[i-2]+arr[i]);
    }
    cout<<dp[n-1];
}
