#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,m;
    int x,y;
    int sum[100000];
    cin>>n>>m;
    sum[0]=0;
    for (int i=1;i<=n;i++){
        cin>>sum[i];
    }
    for (int i=1;i<=n;i++){
        sum[i]+=sum[i-1];
    }
    
    for (int i=0;i<m;i++){
        cin>>x>>y;
        cout<<sum[y]-sum[x-1]<<'\n';
    }
}
