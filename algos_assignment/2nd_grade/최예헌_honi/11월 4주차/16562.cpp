#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 10001

int n,m,k,temp;
vector <pair<int,int>> v;       //가격, 친구 번호
int parent[MAX];
int height[MAX];
bool visit[MAX];
int cnt=0;

int Find(int u){
    if (parent[u]==u)
        return u;
    return parent[u]=Find(parent[u]);
}

void Union(int u,int v){
    u=Find(u);
    v=Find(v);
    
    if (u==v)                //root 노드가 같은 경우 즉, 같은 트리인 경우
        return;
    
    //높이가 낮은 트리를 높이가 큰 트리 밑에 붙임. 즉, 높이가 큰 트리의 root 값을 가지도록 설정
    if (height[u]<height[v])
        swap(u,v);
    parent[v]=u;
    
    if (height[u]==height[v])
        height[u]++;
    return;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int a,x,y;
    
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        cin>>a;
        v.push_back({a,i});
    }
    
    for (int i=1;i<=n;i++){
        parent[i]=i;
    }
    
    for (int i=0;i<m;i++){
        cin>>x>>y;
        Union(x,y);
    }
    
    sort(v.begin(),v.end());
    memset(visit,false,sizeof(visit));
    temp=k;
    
    for (int i=0;i<v.size();i++){
        if (visit[Find(v[i].second)]){       //친구가 이미 친구가 된 경우
            cnt++;
        }
        
        else if (!visit[Find(v[i].second)]){        //친구가 아닌 경우
            if (temp<v[i].first){          //돈이 부족한 경우
                cout<<"Oh no";
                return 0;
            }
            visit[Find(v[i].second)]=true;
            temp -= v[i].first;
            cnt++;
        }
    }
    
    if (cnt==n)
        cout<<k-temp;
    else
        cout<<"Oh no";
    
}
