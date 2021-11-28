#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
#define MAX 200005      //얘 때문임

int parent[MAX];
int arr[MAX];
int t,f;

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
    
    if (v<u)
        swap(u,v);
    
    arr[u]+=arr[v];
    parent[v]=u;
    return;
}


int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    string a,b;
    cin>>t;
    while(t--){
        vector <string> v;
        map <string, int> m;
        int num=0;
        
        cin>>f;
        
        for (int i=0;i<=MAX;i++){
            parent[i]=i;
            arr[i]=1;
        }
        
        for (int i=0;i<f;i++){
            cin>>a>>b;
            
            if (m.find(a)==m.end()){        //맵에 a의 key가 없는 경우
                m.insert({a,num});
                num++;
            }
            
            if (m.find(b)==m.end()){        //맵에 b의 key가 없는 경우
                m.insert({b,num});
                num++;
            }
            
            int x=m[a];
            int y=m[b];
            Union(x,y);
            
            cout<<arr[Find(x)]<<'\n';
        }
    }
}
