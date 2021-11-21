#include <iostream>
#include <vector>
using namespace std;

vector<int> ms, cs;
int dp[101][10001];

int main(){
    int N, M, ans, sum=0;

    cin >> N >> M;
    ms.resize(N+1);
    cs.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> ms[i];
    }
     for(int i=1;i<=N;i++){
        cin >> cs[i];
        sum+=cs[i];
    }
    ans=sum;
    for(int i=0;i<=N;i++){
        dp[0][i]=0;
        dp[i][0]=0;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=sum;j++){
            if(j>=cs[i])
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-cs[i]]+ms[i]);
            else
                dp[i][j]=dp[i-1][j];
            if(dp[i][j]>=M) ans=min(ans, j);
        }
    }
    cout << ans;
}
