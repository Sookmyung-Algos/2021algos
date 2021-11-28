#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001

int parent[MAX];
int n,m;
vector <int> v;

int Find(int u){
    if (parent[u]==u)
        return u;
    return parent[u]=Find(parent[u]);
}

void Union(int u,int v){
    u=Find(u);
    v=Find(v);
    
    if(u==v)
        return;
    
    if (v<u)
        swap(u,v);
    parent[v]=u;
    return;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int x;
    cin>>n>>m;
    
    for (int i=0;i<=n;i++)
        parent[i]=i;
    
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>x;
            if (x==1)
                Union(i,j);
        }
    }
    
    for (int i=0;i<m;i++){
        cin>>x;
        if (i>0){
            if (Find(x)!=Find(v[i-1]) ){
                cout<<"NO";
                return 0;
            }
        }
        v.push_back(x);
    }
    cout<<"YES";
}
