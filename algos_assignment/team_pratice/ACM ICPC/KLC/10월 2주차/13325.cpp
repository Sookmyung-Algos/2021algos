#include <iostream>
#include <cmath>
#define MAX (1<<21)
using namespace std;
typedef long long ll;

int main(){
    
    int k;
    int arr[MAX]={0,};
    int dp[MAX]={0,};
    int num,sum=0;
    
    cin>>k;
    num=1<<(k+1);
    for (int i=2;i<num;i++){
        cin>>arr[i];
        dp[i]=arr[i];
    }
    
    int n=num;
    while (1){
        if (n==1)
            break;
        
        if (n%2==0){
            n--;
            continue;
        }
        
        if (dp[n] == dp[n-1]){
            dp[n/2]+=dp[n];
        }
        else{
            if (dp[n]>dp[n-1]){
                arr[n-1]+=(dp[n]-dp[n-1]);
                dp[n/2]+=dp[n];
            }
            else{
                arr[n]+=(dp[n-1]-dp[n]);
                dp[n/2]+=dp[n-1];
            }
        }
        n--;
    }
    
    for (int i=2;i<num;i++)
        sum+=arr[i];
    
    cout<<sum;
}


