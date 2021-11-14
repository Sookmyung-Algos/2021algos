//복습
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 1010
#define INF 987654321

int n, m, x, ans;
int dist[MAX], res[MAX];
vector<pair<int, int>> v[MAX];

void input(){
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }
}
void dijkstra(int s){
    priority_queue<pair<int, int>> pq;
    dist[s] = 0;
    pq.push(make_pair(0, Start));

    while (pq.empty() == 0){
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[curr].size(); i++){
            int next = v[curr][i].first;
            int ncost = v[curr][i].second;

            if (dist[next] > cost + ncost){
                dist[next] = cost + ncost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

}
void sol() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dist[j] = INF;
        dijkstra(i);
        res[i] = dist[x];
    }
    for (int j = 1; j <= n; j++) dist[j] = INF;
    dijkstra(x);
    for (int i = 1; i <= n; i++) res[i] = res[i] + dist[i];
    sort(res + 1, res + n + 1);
    ans = res[n];
}
int main(void){
    input();
    sol();
    cout << ans;
    return 0;
}
