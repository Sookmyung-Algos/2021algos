#include <iostream>
#include <queue>
using namespace std;

int s;
int vis[1001][1001];

int bfs(){
    queue<pair<int,int> > q;
    int monitor, board, cnt=0;
    q.push(make_pair(1, 1));
    q.push(make_pair(-1,-1));
    while(!q.empty()){
        monitor=q.front().first;
        board=q.front().second;
        q.pop();
        if(monitor==-1 && board==-1){
            cnt++;
            q.push(make_pair(-1,-1));
            continue;
        }
        if(monitor==s){
            cnt++;
            break;
        }
        if(vis[monitor][monitor]!=1){
            q.push(make_pair(monitor, monitor));
            vis[monitor][monitor]=1;
        }
        if(monitor+board<=1000 && vis[monitor+board][board]!=1){
            q.push(make_pair(monitor+board, board));
            vis[monitor+board][board]=1;
        }
        if(monitor>1 && vis[monitor-1][board]!=1){
            q.push(make_pair(monitor-1, board));
            vis[monitor-1][board]=1;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    cout << bfs();
}
