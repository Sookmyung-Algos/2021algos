// 11403(Silver 1) - 경로 찾기
#include <iostream>
#include <vector>
#define INF 1e9
#define MAX 101
using namespace std;

int N;  // N: 정점의 개수
int graph[MAX][MAX];  // 1인 경우 간선 존재, 0인 경우 없음

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >> graph[i][j];
    }
    
    // solution
    for(int middle=0; middle<N; middle++){
        for(int from=0; from<N; from++){
            for(int to=0; to<N; to++){
                if(graph[from][middle] && graph[middle][to])  // 둘 다 1이면
                    graph[from][to] = 1;
            }
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0;j<N;j++)
            cout << graph[i][j] << ' ';
        cout << "\n";
    }
    
    return 0;
}
