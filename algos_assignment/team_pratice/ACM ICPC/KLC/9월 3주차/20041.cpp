#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    ll x,y;
    ll sx,sy;
    vector <pair<ll,ll>> arr;
    bool visit[4];  //[0]: 위, [1]: 아래, [2]: 왼, [3]: 오
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x>>y;
        arr.push_back({x,y});
    }
    cin>>sx>>sy;
    
    for (int i=0;i<arr.size();i++){
        
        ll nx=arr[i].first;
        ll ny=arr[i].second;
        ll dx=abs(sx-nx);
        ll dy=abs(sy-ny);
        
        if (nx<=sx && ny>=sy){   //1
            if (dx<=dy)
                visit[0]=true;
            
            if (dx>=dy)
                visit[2]=true;
        }
        
        else if (nx>=sx && ny>=sy){   //2
            if (dx<=dy)
                visit[0]=true;
            
            if (dx>=dy)
                visit[3]=true;
        }
        
        else if (nx<=sx && ny<=sy){   //3
            if (dx<=dy)
                visit[1]=true;
            
            if (dx>=dy)
                visit[2]=true;
        }
        
        else if (nx>=sx && ny<=sy){   //4
            if (dx<=dy)
                visit[1]=true;
            
            if (dx>=dy)
                visit[3]=true;
        }
    }
    
    bool check=true;
    for (int i=0;i<4;i++){
        if (!visit[i]){
            check=false;
            break;
        }
    }
    
    if (check){
        cout<<"NO";
    }
    else
        cout<<"YES";
    
    return 0;
    
}
