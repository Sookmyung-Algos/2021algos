// 2210 숫자판 점프 (Silver 2)
#include <iostream>
#include <string>
using namespace std;

int board[5][5];
bool exist[1000000];  // 인덱스의 숫자가 만들어졌는지
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1,};
int ans = 0;

void dfs(int depth, int r, int c, int num){
    if(depth == 5){
        if(!exist[num]){
            exist[num] = true;
            ans++;
        }
        return;
    }
    for(int i=0;i<4;i++){
        int nextR = r+dx[i];
        int nextC = c+dy[i];
        if(nextR<0 || nextR>=5 || nextC<0 || nextC>=5)
            continue;
        dfs(depth+1, nextR, nextC, 10*num+board[nextR][nextC]);
    }
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	for(int i=0;i<5;i++){
	    for(int j=0;j<5;j++)
	        cin>>board[i][j];
	}
	for(int i=0;i<5;i++){
	    for(int j=0;j<5;j++)
	        dfs(0, i, j, board[i][j]);
	}
	
	cout << ans;
	return 0;
}
