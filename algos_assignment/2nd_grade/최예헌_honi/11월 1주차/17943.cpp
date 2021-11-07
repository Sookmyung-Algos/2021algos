//누적합
#include <iostream>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,q;
    int a,x,y,d;
    int arr[200001]={0,};
    int dp[200001]={0,};
    int sum=0;
    
    cin>>n>>q;
    for (int i=1;i<n;i++){
        cin>>arr[i];
        
        if (i==1)
            dp[i]=arr[i];
        else        //누적합 저장
            dp[i]=arr[i]^dp[i-1];
    }
    
    while (q--){
        cin>>a;
        if (a==0){
            cin>>x>>y;
            cout<<(dp[y-1]^dp[x-1])<<'\n';
        }
        
        else if (a==1){
            cin>>x>>y>>d;
            cout<<(dp[x-1]^dp[y-1]^d)<<'\n';
        }
    }
}
