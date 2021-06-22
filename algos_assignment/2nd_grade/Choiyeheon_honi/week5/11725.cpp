#include <iostream>
#include <vector>

using namespace std;

bool mark[100001]={false, };
vector <int> a[100001];
int p[100001];

void dfs(int x);

int main(){
    cin.tie(0);  cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N,x,y;
    
    cin>>N;
    for (int i=0;i<N-1;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    
    for (int i=2;i<=N;i++)      //2번 노드부터 부모노드 출력
        cout<<p[i]<<'\n';
}

void dfs(int x){
    int next;
    mark[x]=true;
    for (int i=0;i<a[x].size();i++)
    {
        next=a[x][i];
        if (!mark[next]){       //방문하지 않은 노드인 경우
            p[next]=x;          //그 노드의 부모가 x
            dfs(next);
        }
    }
}
