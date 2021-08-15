#include <cstdio>
#include <queue>
using namespace std;

int n, m;
int startr, startc;
int map[1001][1001];
int diff[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int visit[1001][1001];

void bfs(){
    queue<pair<int,int>> q;
    q.push({startr, startc});
    visit[startr][startc]=0;
    while(!q.empty()){
        int curr=q.front().first;
        int curc=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nextr=curr+diff[i][0];
            int nextc=curc+diff[i][1];
            if(0<=nextr&&nextr<n&&0<=nextc&&nextc<m){
                if(map[nextr][nextc]==1&&visit[nextr][nextc]==0){
                    q.push({nextr,nextc});
                    visit[nextr][nextc]=visit[curr][curc]+1;
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &map[i][j]);
            if(map[i][j]==2){
                startr=i;
                startc=j;
            }
        }
    }
    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visit[i][j]==0&&map[i][j]==1)
                printf("-1 ");
            else
                printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
}
