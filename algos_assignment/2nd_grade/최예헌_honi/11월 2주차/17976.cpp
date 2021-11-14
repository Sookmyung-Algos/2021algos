#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    ll x,l;
    vector <pair<ll,ll>> v;
    
    cin>>n;
    while (n--){
        cin>>x>>l;
        v.push_back({x,x+l});
    }
    
    sort(v.begin(),v.end());
    
    ll s=0;
    ll e=v[v.size()-1].second - v[0].first;
    ll result=0;
    
    while (s<=e){
        ll point=v[0].first;
        bool flag=true;
        ll mid=(s+e)/2;
        
        for (int i=1;i<v.size();i++){
            if (point+mid <= v[i].first)
                point=v[i].first;
            else if (point+mid > v[i].first && point+mid <= v[i].second)
                point=point+mid;
            else{
                flag=false;
                break;
            }
        }
        
        if (flag){
            result=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<result;
}
