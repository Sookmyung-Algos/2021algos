#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector <pair <int,int>> v;
    int dp[101];
    int x,y;
    int maxx=0;
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    
    for (int i=0;i<=n;i++)
        dp[i]=1;
    
    for (int i=1;i<n;i++){
        for (int j=0;j<i;j++){
            if (v[i].second>v[j].second){
                if (dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
        }
        if (dp[i]>maxx)
            maxx=dp[i];
    }
    cout<<n-maxx;
}
