#include <cstdio>
using namespace std;

int n, k;
int graph[401][401];

void floydWarshall() {
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][k] == 1 && graph[k][j] == 1) // 포인트! a가 k보다 늦게, k가 b보다 늦게 일어난 사건이면 i가 j보다 늦게 일어난 사건
                    graph[i][j] = 1;
                else if (graph[i][k] == -1 && graph[k][j]== -1) //i가 k보다 일찍, 그리고 k가 j보다 일찍 일어난       
                    graph[i][j] = -1;
            }
        }
    }
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) 
    { // 초기화해야 함
       int event1st, event2nd;
       scanf("%d %d", &event1st, &event2nd);
       //양방향 그래프 생성
       graph[event1st][event2nd] = -1;
       graph[event2nd][event1st]= 1;
    }
    floydWarshall();
    
    int s;
    scanf("%d ", &s);
    for (int i = 0; i < s; i++)
    {
        int event1, event2;
        scanf("%d %d", &event1, &event2);
        printf("%d\n", graph[event1][event2]);
    }
    return 0;
}
