#include <iostream>
using namespace std;

int dp[31]={0, };

int main(){
    int n;
    cin >> n;
    dp[0]=1; dp[1]=0; dp[2]=3;
    for(int i=3;i<=n;i++){
        dp[i]=3*dp[i-2];
        for(int j=4;j<=i;j+=2){
            dp[i]+=2*dp[i-j];
        }
    }
    cout << dp[n];
}
