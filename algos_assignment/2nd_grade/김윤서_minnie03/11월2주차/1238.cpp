#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 1010
#define INF 987654321
using namespace std;

int n, m, x, ans;
int dist[MAX], res[MAX];
vector<pair<int, int>> v[MAX];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (pq.empty() == 0) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int next_cost = v[cur][i].second;

            if (dist[next] > cost + next_cost) {
                dist[next] = cost + next_cost;
                pq.push({ -dist[next], next });
            }
        }
    }

}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> x; // 마을수(학생수),도로개수,해당마을번호
    for (int i = 0; i < m; i++) {
        int a, b, t; 
        cin >> a >> b >> t; // i번째 도로의 시작점, 끝점, 소요시간
        v[a].push_back(make_pair(b, t));
    }

    // 모든 학생이 x번 마을로 가는데 걸리는 최단소요시간 찾기
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) dist[j] = INF; // 초기화
        dijkstra(i); 
        res[i] = dist[x];
    }
    for (int j = 1; j <= n; j++) dist[j] = INF; // 다익스트라 한번 했으니 다시 초기화
    dijkstra(x); // x에서 다른 마을로 가는데 걸리는 최단소요시간 찾기

    for (int i = 1; i <= n; i++) // 학생이 가는데 걸리는 최단소요시간과 다시 돌아오는데 걸리는 최단소요시간을 합쳐서 저장
        res[i] = res[i] + dist[i]; 
    sort(res + 1, res + n + 1); // 오름차순 나열
    ans = res[n]; // 가장 큰 값 ans에 저장

    cout << ans << endl; // 가장 오래 걸리는 학생의 소요시간 출력

    return 0;
}
