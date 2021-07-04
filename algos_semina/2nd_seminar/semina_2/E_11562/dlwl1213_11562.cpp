//다대다 경로 검색 문제, 플로이드 와샬 알고리즘 적용
//입력값에 따라 배열 값 설정해줌
//최소 몇 개의 길을 일방->양방향으로 바꿔야하는지 구함

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_VERTEX =250;
const int INF = 1<<29;

int main() {
    int n, m; //건물과 길의 수
    int table[MAX_VERTEX+1][MAX_VERTEX+1];
    scanf("%d %d",&n,&m);
  
    for(int i = 0 ; i<=n;i++) {
        for(int j = 0 ; j <= n ;j++){
            if(i!=j)table[i][j]=INF;
            else table[i][j]=0;
        }
    }
  
    for(int i =0 ; i < m ;i++) {
        int u,v,b; //길에 대한 정보
        scanf("%d %d %d",&u,&v,&b);
        if(b==0){
            table[u][v]=0;
            table[v][u]=1;
        }else if ( b ==1 ){
            table[u][v]=0;
            table[v][u]=0;
        }
    }
  
    for(int k=1 ; k<=n;k++) {
        for(int i = 1; i<=n;i++){
            for(int j =1 ;j <= n;j++){
                table[i][j] = min (table[i][j],table[i][k]+table[k][j]);
            }
        }
    }
    int cnt =0 ;
    scanf("%d",&cnt);
    for(int i =0 ; i< cnt;i++) {
        int u ,v;
        scanf("%d %d",&u,&v);
        printf("%d\n",table[u][v]);
        
    }
    return 0;
}
