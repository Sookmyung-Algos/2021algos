//투포인터
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int n,m,x;
vector <pair<int,int>> arr;
int visit[1005];
int cnt=0;

int main(){
    
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>x;
            arr.push_back({x,i});
        }
    }
    
    sort(arr.begin(),arr.end());
    int s=0, e=0;
    int result=1000000001;
    
    while (e<n*m){
        if (visit[arr[e].second]==0)
            cnt++;
        visit[arr[e].second]++;
        e++;
        
        while (cnt==n){
            result=min(result,arr[e-1].first-arr[s].first);
            visit[arr[s].second]--;
            if (visit[arr[s].second]==0)
                cnt--;
            s++;
        }
    }
    cout<<result;
}

