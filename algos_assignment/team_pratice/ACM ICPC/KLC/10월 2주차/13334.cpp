#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;

bool cmp(pair<int,int> a,pair<int,int> b){
    if (a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}

int main(){
    
    int n,d;
    int h,o;
    vector <pair<int,int>> v;
    int dp[100001];
    priority_queue <int,vector<int>,greater<int>> pq;
    int cnt=0,maxx=0;
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>h>>o;
        if (h<o)
            v.push_back({h,o});
        else
            v.push_back({o,h});
    }
    cin>>d;
    sort(v.begin(),v.end(),cmp);
    
    memset(dp,0,sizeof(dp));
    for (int i=0;i<n;i++){
        pq.push(v[i].first);
        cnt++;
        while (pq.top()<(v[i].second-d) && !pq.empty()){
            pq.pop();
            cnt--;
        }
        maxx=max(maxx,cnt);
    }
    
    cout<<maxx;
    
}
