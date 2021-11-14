// 1916(Gold 5) - 최소비용 구하기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 1e9
using namespace std;

int N, M;  // N: 도시 개수, M: 버스 개수 
int s, e, w;  // s도시에서 e도시로 가는데 걸리는 비용 w
int A, B;  // A에서 B로 가는 최소비용 구하기
vector<pair<int, int>> graph[MAX];  // graph[s] = {e,w} -> s에서 e로 가는데 e의 비용
vector<int> cost;  // A에서 출발하면 드는 비용 저장

void Dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // first: cost, second: vertex n.

    pq.push({ 0, A });
    cost[A] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int curCost = pq.top().first;

        pq.pop();

        if (curCost > cost[cur])
            continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nextCost = graph[cur][i].second + curCost;

            if (nextCost < cost[next]) {
                cost[next] = nextCost;
                pq.push({ nextCost, next });
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> M;
    cost.resize(N + 1, INF);

    for (int i = 0; i < M; i++) {
        cin >> s >> e >> w;
        graph[s].push_back({ e,w });
    }

    cin >> A >> B;

    Dijkstra();
    cout << cost[B];
    return 0;
}
