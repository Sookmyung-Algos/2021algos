#include <iostream>
using namespace std;
typedef long long ll;
#define MAX 1000000007

int fpow(ll a,ll b){
    if (b==0)
        return 1;
    ll x=fpow(a,b/2);
    if (b%2==0)
        return (x*x)%MAX;
    else
        return (x*x*a)%MAX;
}

int main(){
    ll t,n;
    cin>>t;
    while (t--){
        cin>>n;
        if (n==1)
            cout<<"1"<<'\n';
        else
            cout<<fpow(2,n-2)<<'\n';
    }
}
