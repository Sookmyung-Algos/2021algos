#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

const int MAX = 1000 + 1;
int N, M;

vector<pair<int, int>> graph[MAX];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

bool visit[MAX];

int main(void){
        ios_base::sync_with_stdio(0);
        cin.tie(0); //cin의 실행속도를 향상시키기 위함

        cin >> N >> M;

        for (int i = 0; i < M; i++){
                 int a, b, c;
                 cin >> a >> b >> c;

                 graph[a].push_back({ c, b });
                 graph[b].push_back({ c, a });
        }

        //1번 정점부터 시작함

        pq.push({ 0, 1 });

        int result = 0;
        while (!pq.empty()){
                 int cost = pq.top().first;
                 int vertex = pq.top().second;
                 pq.pop();

                 if (!visit[vertex]){
                         visit[vertex] = true;
                         result += cost;
                         for (int i = 0; i < graph[vertex].size(); i++) {
                                 int nextCost = graph[vertex][i].first;
                                 int nextVertex = graph[vertex][i].second;

                                 if (!visit[nextVertex])
                                          pq.push({ nextCost, nextVertex });
                         }
                 }
        }

        cout << result << "\n";
        return 0;
}
