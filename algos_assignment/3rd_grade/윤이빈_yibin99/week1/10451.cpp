#include <iostream>
#include <cstring>
using namespace std;

int cnt = 0;
int v[1001];
bool vis[1001] = {false, };
bool fin[1001] = {false, };

void dfs(int i){
    vis[i] = true;
    int next = v[i];
    if(!vis[next])
        dfs(next);
    else if(!fin[next])
        cnt++;
    fin[i]=true;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++)
            cin >> v[i];
        for(int i=1;i<=n;i++)
            if(!vis[i]) dfs(i);
        cout << cnt << "\n";
        cnt = 0;
        memset(v, 0, 1001);
        memset(vis, false, 1001);
        memset(fin, false, 1001);
    }
}
