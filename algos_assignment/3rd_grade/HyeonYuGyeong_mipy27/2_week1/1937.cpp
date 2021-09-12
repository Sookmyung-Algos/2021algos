#include <iostream>
using namespace std;

int n,res=0;
int arr[501][501]={0,};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int t[501][501]={0,};

int dfs(int x,int y){
    int cnt=0;
    
    if (t[x][y]) return t[x][y];
    
    for (int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if (nx>=0 && nx<n && ny>=0 && ny<n){
            if (arr[nx][ny] < arr[x][y]){
                cnt = max(cnt,dfs(nx,ny));
            }
        }
    }
    return t[x][y] = cnt+1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            t[i][j]=dfs(i,j);
            res = max(res,t[i][j]);
        }
    }
    cout << res;
}
