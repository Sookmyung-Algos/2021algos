#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    long long arr[5000];
    int dp[5000];       //최대한 변하지 않는 개수 저장
    int maxx=1;
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    for (int i=0;i<n;i++)
        dp[i]=1;
    
    for (int i=1;i<n;i++){
        for (int j=0;j<i;j++){
            if (arr[i]%arr[j]==0){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        if (maxx<dp[i])
            maxx=dp[i];
    }
    cout<<n-maxx;
}
