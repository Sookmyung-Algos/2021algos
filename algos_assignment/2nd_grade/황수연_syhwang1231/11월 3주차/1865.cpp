// 1865(Gold 3) - 웜홀
#include <iostream>
#include <vector>
#define MAX 501
#define INF 1e9
using namespace std;

int TC, N, M, W;  // TC: 테스트 케이스, 지점 N개, 도로 M개(양방향), 웜홀 W개(단방향)
int S, E, T;
vector<pair<int, int>> map[MAX];  // map[i] = { 도착, 시간 } i는 시작 위치
vector<long long> dist;

// 벨만 포드 알고리즘 사용
void solve(int start){
    dist[start] = 0;  // 시작위치는 거리를 0으로 초기화
    
    for(int i=1; i<=N; i++){
        for(int from=1; from<=N; from++){  // 경유지
            for(int k=0; k<map[from].size(); k++){
                int to = map[from][k].first;
                int cost = map[from][k].second;
                
                if(dist[to]>dist[from] + cost){
                    dist[to] = dist[from] + cost;
                    if(i == N){
                        cout << "YES\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> TC;
    
    while(TC--){
        cin >> N >> M >> W;
        dist.clear();
        dist.resize(N+1);
        fill(dist.begin(), dist.end(), INF);
        for(int i=0; i<M; i++){
            cin >> S >> E >> T;
            map[S].push_back({E, T});  // 길은 양방향
            map[E].push_back({S, T});
        }
        for(int i=0; i<W; i++){
            cin >> S >> E >> T;
            map[S].push_back({E, -T});
        }
        
        solve(1);
        
        for(int i=0; i<=N; i++)
            map[i].clear();  // i가 아닌 이상한 변수 써서 틀렸었음..
            
    }
    return 0;
}
