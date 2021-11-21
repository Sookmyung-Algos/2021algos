//G4_11657 타임머신
#include<iostream>
#include<vector>
#define MAX 505
#define INF 987654321
using namespace std;
 
int N, M;
long long dist[MAX];
vector<pair<pair<int, int>, int>> edge;

void belman(){
    dist[1] = 0;
    for (int i = 1; i <= N - 1; i++){
        for (int j = 0; j < edge.size(); j++){
            int from = edge[j].first.first;
            int to = edge[j].first.second;
            int cost = edge[j].second;
            
            if (dist[from] == INF) continue;
            if (dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
        }
    }
 
    for (int i = 0; i < edge.size(); i++){
        int from = edge[i].first.first;
        int to = edge[i].first.second;
        int cost = edge[i].second;
 
        if (dist[from] == INF) continue;
        if (dist[to] > dist[from] + cost){
            cout << -1 << "\n";
            return;
        }
    }
 
    for (int i = 2; i <= N; i++){
        if (dist[i] == INF) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> N >> M;
    for (int i = 1; i <= N; i++) dist[i] = INF;
    for (int i = 0; i < M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        edge.push_back(make_pair(make_pair(a,b), c));
    }
 
    belman();
    return 0;
}
