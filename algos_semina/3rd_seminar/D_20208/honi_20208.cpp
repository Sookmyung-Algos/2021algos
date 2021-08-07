#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void dfs(int x,int y,int m,int cnt);

int n,m,h,hx,hy;
vector <pair<int,int>> v;
bool visit[11][11];
int dis,mmax=0;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int a;
    cin>>n>>m>>h;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>a;
            if (a==1){
                hx=i;
                hy=j;
            }
            else if (a==2)
                v.push_back(make_pair(i,j));
        }
    }
    dfs(hx,hy,m,0);
    cout<<mmax;
}

void dfs(int x,int y,int m,int cnt){
    if (m<=0)
        return;
    
    if (abs(hx-x)+abs(hy-y)<=m){
        if (cnt>mmax)
            mmax=cnt;
    }

    for (int i=0;i<v.size();i++){
        dis=abs(x-v[i].first)+abs(y-v[i].second);
        if (dis<=m){
            if (!visit[v[i].first][v[i].second]){
                visit[v[i].first][v[i].second]=true;
                dfs(v[i].first,v[i].second,m-dis+h,cnt+1);
                visit[v[i].first][v[i].second]=false;
            }
        }
    }
}
