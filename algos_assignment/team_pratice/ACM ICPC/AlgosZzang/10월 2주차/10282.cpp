#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cnt, sum;

void bfs(vector<pair<int,int> > g[], int n, int c){
    int vis[10001]={0, };
    queue<int> q;
    vis[c]=1;
    q.push(c);
    q.push(0);
    while(!q.empty()){
        int nowc=q.front();
        q.pop();
        for(int i=0;i<g[nowc].size();i++){
            if(vis[g[nowc][i].first]==0){
                vis[g[nowc][i].first]=vis[nowc]+g[nowc][i].second;
                q.push(g[nowc][i].first);
            }
            else{
                if(vis[g[nowc][i].first]>vis[nowc]+g[nowc][i].second){
                    vis[g[nowc][i].first]=vis[nowc]+g[nowc][i].second;
                    q.push(g[nowc][i].first);
                }
            }
        }
    }
    cnt=0; sum=0;
    for(int i=1;i<=n;i++){
        if(vis[i]>0){
            cnt++;
            if(vis[i]>sum) sum=vis[i];
        }
    }
    sum-=1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t>0){
        int n, d, c;
        cin >> n >> d >> c;
        vector<pair<int,int> > g[n+1];
        for(int i=0;i<d;i++){
            int a, b, s;
            cin >> a >> b >> s;
            g[b].push_back(make_pair(a,s));
        }
        bfs(g, n, c);
        cout << cnt << " " << sum << "\n";
        t--;
    }
}
