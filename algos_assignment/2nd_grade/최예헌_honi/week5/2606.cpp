#include <iostream>
#include <vector>

using namespace std;

bool mark[101]={false, };
vector <int> a[101];
int cnt=0;

void dfs(int x);

int main(){
    cin.tie(0);  cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,m,x,y;
    
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    cout<<cnt;
}


void dfs(int x){
    int next;
    mark[x]=true;
    for (int i=0;i<a[x].size();i++)
    {
        next=a[x][i];
        if (!mark[next])
        {
            dfs(next);
            cnt++;              //바이러스 걸린 컴퓨터 수
        }
    }
}
