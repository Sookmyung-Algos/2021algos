#include <iostream>
using namespace std;

int main(){
    int dp[301][301]={0,};
    int m,n,x;
    
    cin>>m>>n;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            cin>>x;
            dp[i][j]=dp[i][j-1]+x;
        }
    }
    
    int cnt=0;
    for (int j=1;j<=n;j++){
        for (int k=0;k<j;k++){
            int s=1,e=1;
            
            while (e<=m){
                if (s==e){
                    if (dp[s][j]-dp[s][k]==10)
                        cnt++;
                    e++;
                }
                
                else{
                    int temp=s;
                    int sum=0;
                    while (temp<=e){
                        sum+=(dp[temp][j]-dp[temp][k]);
                        temp++;
                    }
                    if (sum>=10){
                        if (sum==10)
                            cnt++;
                        s++;
                    }
                    else
                        e++;
                }
                
            }
            
        }
    }
    cout<<cnt;
}
