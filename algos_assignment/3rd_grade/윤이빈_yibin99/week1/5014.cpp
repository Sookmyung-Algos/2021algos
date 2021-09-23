#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
int cnt[1000001] = {0, };
bool vis[1000001] = {false, };
int dx[2] = {1, -1};

void bfs(){
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i:dx){
            int next = now+i;
            if(next>=1 && next<=f && !vis[next]){
                q.push(next);
                vis[next] = true;
                cnt[next] = cnt[now]+1;
            }
        }
    }
}

int main(){
    cin >> f >> s >> g >> u >> d;
    dx[0] *= u;
    dx[1] *= d;
    if(s==g){
        cout << 0;
        return 0;
    }
    else{
        bfs();
        if(cnt[g])
            cout << cnt[g];
        else
            cout << "use the stairs";
    }
}
