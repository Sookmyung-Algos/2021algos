// 1238 파티

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

vector<pair<int, int>> graph[1001];
vector<int> dist;
int d[1001];

int n,m,x;

int dijikstra(int start, int end) {
    //초기화
    for (int i = 1; i <= n; i++) 
        d[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[start] = 0;
    pq.push({ d[start], start });

    while (!pq.empty()) {
        int x = pq.top().second;

        if (x == end)
            return d[end];

        pq.pop();

        for (int i = 0; i < graph[x].size();i++) {
            int nextx = graph[x][i].second;
            int nextcost = graph[x][i].first;

            if (d[nextx] > d[x] + nextcost) {
                d[nextx] = d[x] + nextcost;
                pq.push({ d[nextx], nextx });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> x;

    while (m--) {
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[end].push_back({ cost, start });
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, dijikstra(i, x) + dijikstra(x, i));
    }

    cout << ans << '\n';
    return 0;
}
