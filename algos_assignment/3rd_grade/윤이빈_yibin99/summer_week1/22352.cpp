#include <cstdio>
#include <queue>
using namespace std;

int n, m;
int before[31][31], after[31][31];
bool visit[31][31]={false, };
int diff[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int cnt=0;

bool check(int r, int c){
    int b=before[r][c];
    int a=after[r][c];
    queue<pair<int,int>> q;

    q.push({r,c});
    visit[r][c]=true;

    while(!q.empty()){
        int pr=q.front().first;
        int pc=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr=pr+diff[i][0];
            int nc=pc+diff[i][1];
            if(0<=nr&&nr<n&&0<=nc&&nc<m&&visit[nr][nc]==false){
                if(b==before[nr][nc]){
                    if(a==after[nr][nc]){
                        q.push({nr,nc});
                        visit[nr][nc]=true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    continue;
                }
            }
        }
    }
    if(a==b)
        return true;
    else if(cnt==0){
        cnt++;
        return true;
    }
    else
        return false;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &before[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &after[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visit[i][j]==false){
                if(check(i, j)==false){
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    printf("YES");
}
