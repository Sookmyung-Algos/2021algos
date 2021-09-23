#include <iostream>
#include <vector>

using namespace std;

bool mark[1001]={false, };
vector <int> a[1001];

void dfs(int x);

int main(){
    cin.tie(0);  cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N,M,u,v;
    int cnt=0;
    cin>>N>>M;
    
    for (int i=0;i<M;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    for (int i=1;i<=N;i++)
    {
        if (!mark[i])           //방문하지 않은 노드인 경우
        {
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt;              //연결된 요수의 개수
}

void dfs(int x){
    int next;
    mark[x]=true;
    for (int i=0;i<a[x].size();i++)
    {
        next=a[x][i];
        if (!mark[next])        //방문하지 않은 노드인 경우
            dfs(next);          //재귀
    }
}
