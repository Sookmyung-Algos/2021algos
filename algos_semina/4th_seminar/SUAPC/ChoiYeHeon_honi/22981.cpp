#include <iostream>
#include <algorithm>
#define MAX 1000000001
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    ll n,k;
    ll arr[200001];
    
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll maxx=0;

    for (ll i=n-1;i>0;i--){
        ll x=arr[i]*(n-i)+arr[0]*i;
        if (maxx<x) {
            maxx=x;
        }
    }
    
    if (k%maxx==0)
        cout<<k/maxx;
    else
        cout<<(k/maxx)+1;
}
