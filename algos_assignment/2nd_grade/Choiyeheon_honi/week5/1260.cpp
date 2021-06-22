#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

bool mark[1001]={false, };
vector <int> a[1001];
queue <int> q;

void bfs(int x);
void dfs(int x);

int main(){
    cin.tie(0);  cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N,M,V,x,y;
    
    cin>>N>>M>>V;
    for (int i=0;i<M;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    for (int i=0;i<=N;i++)
        sort(a[i].begin(),a[i].end());
    
    dfs(V);
    cout<<'\n';
    memset(mark,false,sizeof(mark));        //mark 초기화
    bfs(V);
}

void bfs(int x){
    int temp, next;
    
    mark[x]=true;
    q.push(x);
    
    while (!q.empty()){
        temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for (int i=0;i<a[temp].size();i++)
        {
            next=a[temp][i];
            
            if (!mark[next])        //방문하지 않은 노드인 경우
            {
                mark[next]=true;    //방문
                q.push(next);       //큐에 삽입
            }
        }
    }
}

void dfs(int x){
    int next;
    mark[x]=true;
    cout<<x<<" ";
    for (int i=0;i<a[x].size();i++)
    {
        next=a[x][i];
        if (!mark[next])        //방문하지 않은 노드인 경우
            dfs(next);          //재귀
    }
}
