// 11404(Gold 4) - 플로이드
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
#define INF 1e9  // INF 값 너무 작게 잡아서 99%에서 틀렸었음.
using namespace std;

int n, m;  // n: 도시 개수, m: 버스 개수
int a, b, c;  // a: 시작, b: 도착, c: 비용
int graph[MAX][MAX];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    cin >> m;
    
    fill(&graph[0][0], &graph[MAX-1][MAX-1], INF);
    
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        if(graph[a][b] > c)  // 최단 비용일 때만 저장해야함
            graph[a][b] = c;
    }
    
    // 플로이드-와샬 알고리즘
    for(int mid=1; mid<=n; mid++){  // mid를 거쳐 from에서 to로 가는 경로
        for(int from=1; from<=n; from++){
            for(int to=1; to<=n; to++){
                if(graph[from][mid] != INF && graph[mid][to])
                    graph[from][to] = min(graph[from][to], graph[from][mid]+graph[mid][to]);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(graph[i][j] == INF || i == j)  // i == j인 경우 고려해야함!
                cout << 0 << ' ';
            else
                cout << graph[i][j] << ' ';
        }
        cout << "\n";
    }

    return 0;
}
