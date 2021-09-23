#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,x,p;
    vector <pair<ll,ll>> arr;
    ll sum=0,maxx=0,cnt=0;
    
    cin>>n;
    for (int i=0;i<n;i++){          //상금 상한과 상금
        cin>>x>>p;
        arr.push_back({x,p});
    }
    
    for (int i=0;i<n;i++){
        if (sum<=arr[i].first){         //합이 상금 상한 이하인 경우
            sum+=arr[i].second;
            maxx=max(maxx,arr[i].second);
        }
        
        else{               //합이 상금 상한보다 큰 경우
            if (sum-maxx<=arr[i].first){
                if (sum<=arr[i+1].first){
                    if (sum-maxx+arr[i].second<sum){
                        sum=sum-maxx+arr[i].second;
                    }
                    else
                        i++;
                }
                else
                    sum=sum-maxx+arr[i].second;
            }
            cnt++;
        }
        if (cnt>1){
            cout<<"Zzz";
            return 0;
        }
    }
    cout<<"Kkeo-eok";
}
