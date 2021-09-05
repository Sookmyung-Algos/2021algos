#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int amount[10001];
int dp[10001][3];
int ans;

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &amount[i]);
    ans=amount[0]+amount[1];
    dp[0][0]=amount[0]; dp[0][1]=amount[0]; dp[0][2]=amount[0];
    dp[1][0]=amount[1]; dp[1][1]=amount[0]+amount[1]; dp[1][2]=amount[0]+amount[1];
    for(int i=2;i<n;i++){
        dp[i][0]=max({dp[i-2][0], dp[i-2][1], dp[i-2][2]})+amount[i];
        dp[i][1]=dp[i-1][0]+amount[i];
        dp[i][2]=dp[i-1][1];
        if(dp[i][0]>ans) ans=dp[i][0];
        if(dp[i][1]>ans) ans=dp[i][1];
        if(dp[i][2]>ans) ans=dp[i][2];
    }
    printf("%d", ans);
}
