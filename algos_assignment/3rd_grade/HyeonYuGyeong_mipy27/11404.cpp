//
//  main.cpp
//  B11404
//
//  Created by 현유경 on 2021/04/08.
//
//  n개의 도시, m개의 버스
//  버스 시작 도시 a, 도착 도시 b, 한 번 타는데 필요한 비용 c
//  a에서 b로 가는데 필요한 최소 비용 구하기

#include <iostream>
#define INF 10000000
using namespace std;

int n,m;
int graph[101][101];
int a,b,c;

void floydWarshall(){
    for (int k=1;k<=n;k++){
        for (int a=1;a<=n;a++){
            for (int b=1;b<=n;b++){
                /* 다른 도시를 거쳐가는 방법의 수가 더 작으면 값 갱신 */
                if (graph[a][b] > graph[a][k] + graph[k][b]){
                    graph[a][b] = graph[a][k] + graph[k][b];
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    /* a==b를 제외한 배열의 값을 INF로 초기화 */
    for (int a=1;a<=n;a++){
        for (int b=1;b<=n;b++){
            if (a!=b)
                graph[a][b]=INF;
        }
    }
    for (int i=0;i<m;i++){
        cin >> a >> b >> c;
        /* 비용 c가 현재 배열의 값보다 작으면 값 갱신 */
        if (graph[a][b]>c){
            graph[a][b]=c;
        }
    }
    floydWarshall();
    
    /* 2차원 배열 출력 */
    for (int a=1;a<=n;a++){
        for (int b=1;b<=n;b++){
            if (graph[a][b]==INF) cout << 0 << " ";
            else cout << graph[a][b] << " ";
        }
        cout << '\n';
    }
    return 0;
}
