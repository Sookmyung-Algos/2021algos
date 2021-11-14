// 1916 최소비용

#include <iostream> 
#include <queue> 
#include <vector> 
#include <algorithm> 
using namespace std; 

#define INF 1e9
vector<pair <int, int>> road[1001]; 
int d[1001];

void dijkstra(int start) { 

    priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; 
   
    fill_n(d, 1001, INF);
    d[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) { 
        int cost = pq.top().first; 
        int curr = pq.top().second;
        
        pq.pop(); 
        
        if (cost > d[curr]) {
            continue; 
        } 
        
        for (int i = 0; i < road[curr].size(); i++) {
            int next = road[curr][i].first;
            int next_cost = d[curr] + road[curr][i].second;
            
            if (next_cost < d[next]) { 
                d[next] = next_cost; 
                pq.push({ next_cost,next }); 
            } 
        } 
    } 
} 

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    int n, m;   // 도시개수, 버스 개수
    int a, b, c;    // 출발도시번호, 도착도시번호, 버스비용

    cin >> n >> m; 

    for (int i = 0; i < m; i++) { 
        cin >> a >> b >> c;
        road[a].push_back({ b,c }); 
    } 

    int start, end; // 구하고자 하는 구간의 출발도시번호, 도착도시번호
    cin >> start >> end;
    
    dijkstra(start);
    
    cout << d[end]; 
    return 0; 
}
