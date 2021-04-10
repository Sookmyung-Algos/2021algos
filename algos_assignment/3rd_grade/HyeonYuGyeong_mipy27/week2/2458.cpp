//
//  main.cpp
//  B2458
//
//  Created by 현유경 on 2021/04/10.
//
//  In: N명의 학생, 두 학생의 키를 비교한 횟수 M, 키를 비교한 결과 a,b
//  Out: 자신의 키가 몇 번째인지 알 수 있는 학생 수 출력

#include <iostream>
using namespace std;

int n,m,a,b;
int graph[501][501];

int main() {
    cin >> n >> m;
    
    /* 배열에 두 학생의 키를 비교한 결과 반영 */
    for (int i=1;i<=m;i++){
        cin >> a >> b;
        graph[a][b] = 1;
    }
    /* floydwarshall */
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i==j || j==k || k==i) continue;
                // 키 관계가 연결되면 1로 바꾸기
                if (graph[i][k] == 1 && graph[k][j] == 1)
                    graph[i][j]=1;
            }
        }
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        int t=0; //t는 알고 있는 관계 수
        for (int j=1;j<=n;j++){
            if (graph[i][j]||graph[j][i]) t++; //해당 관계가 모두 1이면 t증가
        }
        // 알고 있는 관계 수가 n-1이면 cnt 증가
        if (t==n-1) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
