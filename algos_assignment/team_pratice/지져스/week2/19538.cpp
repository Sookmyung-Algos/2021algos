#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(void);

vector <int> v[200001];
queue <int>q;
int vtime[200001];

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n,x,m,y;
    cin>>n;
    
    for (int i=1;i<=n;i++){
        while (1){
            cin>>x;
            if (x==0)
                break;
            v[i].push_back(x);
        }
    }
    
    for (int i=1;i<=n;i++)
        vtime[i]=-1;
    
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>y;
        vtime[y]=0;
        q.push(y);
    }
    bfs();
    
    for (int i=1;i<=n;i++)
        cout<<vtime[i]<<' ';
    
    return 0;
}

void bfs(void){
    int temp,next,cnt;

    while (!q.empty()){
        temp=q.front();
        q.pop();

        for (int i=0;i<v[temp].size();i++){
            next=v[temp][i];
            
            if (vtime[next]<0){
                cnt=0;
                for (int j=0;j<v[next].size();j++){
                    if (vtime[v[next][j]]>=0&&vtime[v[next][j]]<=vtime[temp])
                        cnt++;
                }
    
                if (cnt*2>=v[next].size()){
                    vtime[next]=vtime[temp]+1;
                    q.push(next);
                }
            }
        }
    }
}
