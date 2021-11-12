// 2447(Silver 1) - 별 찍기-10
#include <iostream>
#define MAX 6561  // 3^8
using namespace std;

int n;
char stars[MAX][MAX];

void solve(int n, int x, int y){  // x,y는 그리기 시작할 공간의 왼쪽 상단 좌표
    if(n == 3){  // base case
        stars[x][y] = '*';
        stars[x+1][y] = '*';
        stars[x+2][y] = '*';
        stars[x][y+1] = '*';
        stars[x+2][y+1] = '*';
        stars[x][y+2] = '*';
        stars[x+1][y+2] = '*';
        stars[x+2][y+2] = '*';
        return;
    }
    
    solve(n/3, x, y);  // 첫번째 행
    solve(n/3, x+n/3, y);
    solve(n/3, x+2*n/3, y);
    solve(n/3, x, y+n/3);  // 두번째 행 (중간의 공백 부분은 호출X)
    solve(n/3, x+2*n/3, y+n/3);
    solve(n/3, x, y+2*n/3);  // 세번째 행
    solve(n/3, x+n/3, y+2*n/3);
    solve(n/3, x+2*n/3, y+2*n/3);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    fill(&stars[0][0], &stars[MAX-1][MAX-1], ' ');
    
    cin >> n;
    solve(n, 0, 0);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << stars[i][j];
        cout << "\n";
    }
    
    return 0;
}
