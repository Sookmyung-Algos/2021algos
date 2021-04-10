#include <iostream>

using namespace std;
 
#define INF 10000000 //범위 주의* 100000 * 100 개를 지날 수도 있음

int n, m;
int graph[110][110];
int a, b, c;
 
void floydWarshall() {
    for (int k = 1; k <= n; k++)             // i vertex를 거치는 경우
        for (int i = 1; i <= n; i++)         // 출발도시
            for (int j = 1; j <= n; j++)     // 도착도시
                if (graph[i][k] && graph[k][j])        
                    graph[i][j] = 1;
}
int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) 
    {   
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }
    floydWarshall();
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (!graph[i][j] && !graph[j][i])
                cnt++;
        }
        cout << cnt-1 << endl;
    }
    return 0;
}
