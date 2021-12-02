#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 1000001

int parent[MAX];
int n,m;

int Find(int u){
    if(parent[u]==u)
        return u;
    return parent[u]=Find(parent[u]);
}

void Union(int u,int v){
    u=Find(u);
    v=Find(v);
    
    if (u==v)
        return;
    
    if (u<=v)
        parent[v]=u;
    else
        parent[u]=v;
    
    return;
    
}

bool check(int u,int v){
    u=Find(u);
    v=Find(v);
    
    if (u==v)
        return true;
    else
        return false;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int x,a,b;
    
    cin>>n>>m;
    
    for (int i=0;i<=n;i++)
        parent[i]=i;
    
    for (int i=0;i<m;i++){
        cin>>x>>a>>b;
        if (x==0){
            Union(a,b);
        }
        
        if (x==1){
            if (check(a,b))
                cout<<"YES"<<'\n';
            else
                cout<<"NO"<<'\n';
        }
    }
}
