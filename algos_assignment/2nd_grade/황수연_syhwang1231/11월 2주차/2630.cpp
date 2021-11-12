// 2630(Silver 3) - 색종이 만들기
#include <iostream>
#define MAX 128
using namespace std;

int N;
int board[MAX][MAX];
int white, blue;  // 하얀색(0)으로 칠해진 칸, 파란색(1)으로 칠해진 칸

void solve(int x, int y, int size){
    if(size == 1){  // base case
        if(board[x][y] == 0)
            white++;
        else
            blue++;
        return;
    }
    
    // 잘린 색종이가 같은 색인지 판단하기
    int check = board[x][y];
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(check != board[i][j]){  // 같지 않다 -> 분할
                solve(x, y, size/2);
                solve(x+size/2, y, size/2);
                solve(x, y+size/2, size/2);
                solve(x+size/2, y+size/2, size/2);
                return;
            }
        }
    }
    // 같다 -> 정복(숫자 세기)
    
    if(check == 0)
        white++;
    else
        blue++;
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
        }
    }
    solve(0, 0, N);
    cout << white << "\n" << blue;
    return 0;
}
