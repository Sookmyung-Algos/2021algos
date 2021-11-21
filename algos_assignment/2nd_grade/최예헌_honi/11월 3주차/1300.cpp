//이진탐색
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    ll n,k;
    ll sum;
    ll result=0;
    
    cin>>n>>k;
    
    ll left=1;
    ll right=n*n;
    
    while (left<=right){
        ll mid=(left+right)/2;
        
        sum=0;
        for (int i=1;i<=n;i++){
            sum+=min(n,mid/i);
        }
        
        if (sum>=k){
            result=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    
    cout<<result;
}

