#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    ll dp[50001];
    
    cin>>n;
    ll temp=sqrt(n);
    
    for (int i=1;i<=n;i++)
        dp[i]=i;
    
    for (int i=2;i<=temp;i++){
        dp[i*i]=1;
    }

    for (int i=1;i<=n;i++){
        if (dp[i]==1)
            continue;
        
        for (int j=1;j<=temp && j*j<=i;j++){
            dp[i]=min(dp[i],dp[j*j]+dp[i-j*j]);
        }
    }
    cout<<dp[n];
}
