#include <cstdio>
using namespace std;

int n;
int tri[501*502/2];
long long int dp[501*502/2];
long long int ans;

void calc(int floor, int idx){
    int i=idx;
    dp[i]=dp[i-floor+1]+tri[i];
    if(floor==n)
        ans=dp[i];
    for(i=idx+1;i<idx+floor-1;i++){
        dp[i]=(dp[i-floor]>dp[i-floor+1]?dp[i-floor]:dp[i-floor+1])+tri[i];
        if(floor==n&&dp[i]>ans)
            ans=dp[i];
    }
    dp[i]=dp[i-floor]+tri[i];
    if(floor==n&&dp[i]>ans)
        ans=dp[i];
    if(floor!=n)
        calc(floor+1, i+1);
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n*(n+1)/2;i++){
        scanf("%d", &tri[i]);
    }
    dp[1]=tri[1];
    ans=dp[1];
    if(n>1)
        calc(2, 2);
    printf("%lld", ans);
}
