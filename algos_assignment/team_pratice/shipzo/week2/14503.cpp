#include <iostream>
using namespace std;

int n, m, cnt=0;
int space[50][50];
int go[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int back[4][2]={{1,0},{0,-1},{-1,0},{0,1}};

void clean(int r, int c, int d){
    int next_r, next_c, next_d, i;
    if(space[r][c]==0){
        space[r][c]=-1;
        cnt+=1;
    }
    for(i=0;i<4;i++){
        next_d=d-1;
        if(next_d<0)
            next_d=3;
        next_r=r+go[next_d][0];
        next_c=c+go[next_d][1];
        if(space[next_r][next_c]==0){
            clean(next_r, next_c, next_d);
            break;
        }
        else{
            d=next_d;
        }
    }
    if(i==4){
        next_r=r+back[d][0];
        next_c=c+back[d][1];
        if(space[next_r][next_c]!=1)
            clean(next_r, next_c, d);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int r, c, d;
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> space[i][j];
        }
    }
    clean(r, c, d);
    cout << cnt;
}
