// 11675(Gold 4) - 타임머신
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 501
#define INF 1e9
using namespace std;

int N, M;  // N:도시 개수, M: 버스 노선 개수
int a, b, c;
vector<pair<int, int>> buses[MAX];  // first:도착 도시, second: 걸리는 시간
vector<long> dist;  // int였을 때 출력초과였음 -> long으로 고치니까 해결(음수 사이클 돌게 될 때를 고려해야 하기 때문에)
bool isCycle;

void belmanFord(int start){
    dist[start] = 0;  // 시작점은 0으로 초기화(시작점에서 시작점이므로)
    
    for(int i=1; i<=N; i++){  // N번 탐색
        for(int from=1; from<=N; from++){  // 경유지 지정
            for(int k=0; k<buses[from].size(); k++){
                int to = buses[from][k].first;
                int cost = buses[from][k].second;  // from에서 to 까지 가중치 cost
                
                // dist[from]값이 무한대인 경우는 판단하지 않음. (갱신 불가능하기 때문)
                if(dist[from] != INF && dist[to] > dist[from] + cost){  // 값을 새로 갱신
                    dist[to] = dist[from] + cost;
                    if(i == N)  // 원래대로라면 n-1번 안에 최단거리가 완성되어야 하기 때문에.
                        isCycle=true;
                }
            }
        }
    }
    
    if(isCycle)
        cout << -1;
    else{
        for(int i=2;i<=N;i++){
            if(dist[i] == INF)
                cout << -1 << "\n";
            else
                cout << dist[i] << "\n";
        }
    }
        
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    dist.resize(N+1);
    fill(dist.begin(), dist.end(), INF);
    
    for(int i=0;i<M;i++){
        cin >> a >> b >> c;
        buses[a].push_back({b,c});
    }
    
    belmanFord(1);  // 1번에서 시작
    
    return 0;
}
