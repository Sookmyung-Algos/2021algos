//1865 웜홀

#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int N, M, W;    // 지점의 수, 도로의 개수, 웜홀의 개수
vector<vector<pair<int, int>>> adj;

bool bellman(int src) {
    vector<int> upper(N + 1, INF);
    bool is_updated = false;

    upper[src] = 0;

    int next, cost;
    for (int iter = 0; iter < N; ++iter) {
        is_updated = false;

        for (int idx = 1; idx <= N; ++idx) {
            for (int i = 0; i < adj[idx].size(); ++i) {
                next = adj[idx][i].first;
                cost = adj[idx][i].second;


                if (cost + upper[idx] < upper[next]) {
                    upper[next] = cost + upper[idx];
                    is_updated = true;
                }
            }
        }

        if (!is_updated) // 모든 경로 탐색 전 갱신 없어짐 = 음의 사이클 X = 완화될 가능성 없음
            break;
    }

    if (is_updated)  // 모든 경로 탐색 후에도 갱신됨 = 음의 사이클 O
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;

    cin >> TC;

    while (TC--) {
        cin >> N >> M >> W;
        adj = vector<vector<pair<int, int>>>(N + 1);

        int s, e, t;    // 시작지점, 도착지점, 이동시간

        for (int i = 0; i < M; ++i) { // 양방향 도로
            cin >> s >> e >> t;
            adj[s].push_back({ e,t });
            adj[e].push_back({ s,t });
        }

        for (int i = 0; i < W; ++i) { // 단방향 웜홀
            cin >> s >> e >> t;
            adj[s].push_back({ e,-t });
        }

        bool is_pos = bellman(1);
        if (is_pos)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}
