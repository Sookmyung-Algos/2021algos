#include <iostream>
#include <vector>
#define INF 1e9     //무한을 의미하는 값으로 10억을 지정 

using namespace std;

int graph[101][101];
int n, m,cnt;    //n=도시의 개수, m=버스의 개수
int path[101][101];

void findCost(int a, int b)    {    //경로에 포함된 도시의 개수를 구하는 함수
    if (path[a][b] != INF) {
        cnt++;
        findCost(a, path[a][b]);
        findCost(path[a][b], b);
    }
}

void findPath(int a, int b) {    //재귀적으로 호출하면서 경로를 출력하는 함수
    if (path[a][b] != INF) {
        findPath(a, path[a][b]);
        cout << path[a][b] << ' ';
        findPath(path[a][b], b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < 101; i++) {        //최단 거리 테이블을 무한으로 초기화;
        fill(graph[i], graph[i] + 101, INF);
        fill(path[i], path[i] + 101, INF);
    }

    for (int a = 1; a <= n; a++) {        //자기 자신에서 자기 자신으로 가는 비용은 0
        for (int b = 1; b <= n; b++) {
            if (a == b) {
                graph[a][b] = 0;
                path[a][b] = 0;
            }
        }
    }


    for (int i = 0; i < m; i++) {    //간선 정보 입력
        int a, b, c; cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);    //a에서 b까지 가는데 c만큼의 비용이 든다.
    }

    for (int k = 1; k <= n; k++) {        //플로이드-와샬 알고리즘 수행
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                if (graph[a][k] + graph[k][b] < graph[a][b]) {
                    graph[a][b] = graph[a][k] + graph[k][b];
                    path[a][b] = k;
                }
            //    graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }

        }
    }
    for (int a = 1; a <= n; a++) {        //i->j로 가는데 필요한 최소 비용 출력    
        for (int b = 1; b <= n; b++) {
            if (graph[a][b] == INF) cout << 0 << ' ';
            else cout << graph[a][b] << ' ';
        }
        cout << "\n";
    }

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (graph[a][b] == INF||a==b) cout << 0<<'\n';
            else {
                cnt = 2;    //시작과 끝은 무조건 지나므로 2부터 시작
                findCost(a, b);
                cout << cnt << ' ' << a << ' ';
                findPath(a, b);
                cout << b << "\n";
            }
        }
    }


}
