#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    ll map[1001][1001];
    bool visit[1001][1001];
    ll sum=0;
    
    memset(visit,false,sizeof(visit));
    
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>map[i][j];
            sum+=map[i][j];
        }
    }
    
    for (int i=0;i<n;i++){
        ll max1=0,temp1=0;
        for (int j=0;j<m;j++){
            if (max1<map[i][j]){
                max1=map[i][j];
                temp1=j;
            }
        }
        if (!visit[i][temp1]){
            visit[i][temp1]=true;
            sum-=map[i][temp1];
        }
    }
    
    for (int j=0;j<m;j++){
        ll max2=0,temp2=0;
        for (int i=0;i<n;i++){
            if (max2<map[i][j]){
                max2=map[i][j];
                temp2=i;
            }
        }
        if (!visit[temp2][j]){
            visit[temp2][j]=true;
            sum-=map[temp2][j];
        }
    }
    cout<<sum;
}


