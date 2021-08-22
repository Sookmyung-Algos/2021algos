#include <cstdio>
#include <queue>
using namespace std;

int n, m;
int map[1001][1001];
int visit[1001][1001][2];
int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int bfs(){
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},1});
    visit[0][0][1]=1;
    while(!q.empty()){
        int curr=q.front().first.first;
        int curc=q.front().first.second;
        int capa=q.front().second;
        q.pop();
        
        if(curr==n-1&&curc==m-1)
    		return visit[curr][curc][capa];
        
        for(int i=0;i<4;i++){
            int nextr=curr+d[i][0];
            int nextc=curc+d[i][1];
            if(nextr<0||nextr>=n||nextc<0||nextc>=m)
                continue;
            if(map[nextr][nextc]==1&&visit[nextr][nextc][0]==0&&capa==1){
            	q.push({{nextr,nextc},0});
            	visit[nextr][nextc][0]=visit[curr][curc][capa]+1;
            }
            else if(map[nextr][nextc]==0&&visit[nextr][nextc][capa]==0){
            	q.push({{nextr,nextc},capa});
            	visit[nextr][nextc][capa]=visit[curr][curc][capa]+1;
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d %d", &n, &m);
    char tmp[1001];
    for(int i=0;i<n;i++){
    	scanf("%s", tmp);
        for(int j=0;j<m;j++){
            map[i][j]=tmp[j]-'0';
        }
    }
    printf("%d", bfs());
}
