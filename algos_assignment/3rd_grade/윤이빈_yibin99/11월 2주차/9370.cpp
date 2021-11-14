#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff

vector<pair<int,int>> graph[2001];
vector<int> cand;
int distS[2001], distG[2001], distH[2001];

void dijkstra(int s, int* dist){
    priority_queue<pair<int,int>> pq;
    fill(dist, dist+2001, INF);
    dist[s]=0;
    pq.push({0, s});//-dist, v

    while(!pq.empty()){
        int d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(d>dist[u]) continue;

        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i].first;
            int c = graph[u][i].second;
            if(dist[v]>dist[u]+c){
                dist[v]=dist[u]+c;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T>0){
        int n, m, t;
        cin >> n >> m >> t;
        int s, g, h;
        cin >> s >> g >> h;
        int ghDist;
        if(h<g){
            int tmp=h;
            h=g;
            g=tmp;
        }
        for(int i=0;i<m;i++){
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back({b,d});
            graph[b].push_back({a,d});
            if(a==g && b==h) ghDist = d;
        }
        for(int i=0;i<t;i++){
            int x;
            cin >> x;
            cand.push_back(x);
        }
        
        sort(cand.begin(), cand.end());
        dijkstra(s, distS);
        dijkstra(g, distG);
        dijkstra(h, distH);
        for(int i=0;i<cand.size();i++){
            int v = cand[i];
            if(distS[v]==distS[g]+ghDist+distH[v] || distS[v]==distS[h]+ghDist+distG[v]) cout << v << " ";
        }
        cout << "\n";
        for(int i=1;i<=n;i++) graph[i].clear();
        cand.clear();
        T--;
    }
}
