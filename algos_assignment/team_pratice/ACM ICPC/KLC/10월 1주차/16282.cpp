#include <iostream>
using namespace std;
typedef long long ll;

int sum(int n);

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    ll sum=0;
    cin>>n;
    
    for (int i=1;i<=n;i++){
        sum=0;
        ll num=1;
        for (int j=0;j<i+1;j++){
            sum+=num;
            num*=2;
        }
        if (n<=(i+1)*sum+i){
            cout<<i;
            return 0;
        }
    }
}
