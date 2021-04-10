//
//  main.cpp
//  B1613
//
//  Created by 현유경 on 2021/04/08.
//

#include <iostream>
using namespace std;

int n,k,s;
int graph[401][401];

void floydWarshall(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                // 시간 순서가 j,i,k 일 때 j가 k보다 후행 사건이므로 1 저장
                if (graph[j][i]==1 && graph[i][k]==1){
                    graph[j][k]=1;
                }
                // 시간 순서가 k,i,j 일 때 k가 j보다 선행 사건이므로 -1 저장
                else if (graph[j][i]==-1 && graph[i][k]==-1){
                    graph[j][k]=-1;
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            graph[i][j]=0;
        }
    }
    /* 입력 적용하여 배열 값 대입 */
    for (int i=0;i<k;i++){
        int event1,event2;
        cin >> event1 >> event2;
        graph[event1][event2]=-1;
        graph[event2][event1]=1;
    }
    
    floydWarshall();
    
    /* 관계를 알고 싶은 사건 입력받고 출력하기 */
    cin >> s;
    for (int i=0;i<s;i++){
        int event1,event2;
        cin >> event1 >> event2;
        cout << graph[event1][event2] << '\n';
    }
    return 0;
}
