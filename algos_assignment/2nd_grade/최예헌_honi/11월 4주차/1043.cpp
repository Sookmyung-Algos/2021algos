#include <iostream>
#include <vector>
using namespace std;

int parent[52];
int n,m;
int cnt=0;
vector <int> v;
vector <int> arr[52];
bool check[52];

int Find(int u){
    if (parent[u]==u)
        return u;
    return parent[u]=Find(parent[u]);
}

void Union(int u,int v){
    u=Find(u);
    v=Find(v);
    
    if (u==v)
        return;
    
    if (v<u)
        swap(u,v);
    parent[v]=u;
    return;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int a,b;       //진실 아는 사람 수, 번호
    int x,y;            //파티 사람 수, 번호
    cin>>n>>m;
    
    cin>>a;
    while (a--){
        cin>>b;
        v.push_back(b);
    }
    
    for (int i=0;i<=n;i++)
        parent[i]=i;
    
    for (int i=1;i<=m;i++){
        cin>>x;
        
        for (int j=0;j<x;j++){
            cin>>y;
            if (j!=0){
                Union(arr[i][j-1],y);
            }
            arr[i].push_back(y);
        }
    }
    
    for (int i=0;i<v.size();i++){
        check[Find(v[i])]=true;
    }
    
    for (int i=1;i<=m;i++){
        bool flag=true;
        
        for (int j=0;j<arr[i].size();j++){
            if (check[Find(arr[i][j])]){
                flag=false;
                break;
            }
        }
        if (flag)
            cnt++;
    }
    cout<<cnt;
}
