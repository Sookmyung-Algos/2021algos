#include <iostream>
using namespace std;
typedef long long ll;

int t;
ll n,k;

void check(ll x, ll y) {
    if (x-y-1<=0)
        cout<<x*(4+2*(x-1))<<'\n';
    else
        cout<<(x*(4+2*(x-1)))-((x-y-1)*(4+2*(x-y-2)))<<'\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>t;
    while (t--){
        ll x, y;
        cin>>x>>y;
        check(x,y);
    }
    return 0;
}
