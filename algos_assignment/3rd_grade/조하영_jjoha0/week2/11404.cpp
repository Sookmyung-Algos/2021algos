#include <iostream>

using namespace std;
 
#define INF 10000000 //범위 주의* 100000 * 100 개를 지날 수도 있음

int n, m;
int graph[101][101];
int a, b, c;
 
void floydWarshall() {
    for (int k = 1; k <= n; k++)             // i vertex를 거치는 경우
        for (int a = 1; a <= n; a++)         // 출발도시
            for (int b = 1; b <= n; b++)     // 도착도시
                if (graph[a][b] > graph[a][k] + graph[k][b])        
                    graph[a][b] = graph[a][k] + graph[k][b];
}
int main(){
    cin >> n >> m;
    for (int a = 1; a <= n; a++) {        // 초기화해야 함.
        for (int b = 1; b <= n; b++) {
            if(a != b)//대각 값(자신에게 들어오는 경로)제외. why? 경유값이 더 작아지는 수가 나오기때문에 대각선 값이 갱신 되버리는 오류 발생
                graph[a][b] = INF;
        }
    }
    for (int i = 0; i < m; i++) {  // 버스 수 만큼 a도시에서 b도시, 버스 비용
        cin >> a >> b >> c;
        if (graph[a][b] > c) //INF로 초기화한 배열에 입력
            graph[a][b] = c;
    }
    floydWarshall();
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (graph[a][b] == INF)
                cout << 0 << " ";
            else
                cout << graph[a][b] << " ";
        }
        cout << endl;
    }
    return 0;
}
