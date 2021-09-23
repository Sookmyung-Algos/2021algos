// 9663: N-QUEEN(Gold 5)
#include <iostream>
#define MAX 15
using namespace std;

int n;
int cnt = 0;
int board[MAX];  // 원소 값은 열 번호

bool isAble(int idx){
    for(int i=0;i<idx;i++){
        if(idx-i == abs(board[idx]-board[i]) || board[idx] == board[i])  // 대각선에 있거나 위 아래에 있다면
            return false;
    }    
    return true;
}

void sol(int idx){  // 한 행씩 진행
    if(idx == n){
        cnt++;
        return;
    }
    
    for(int i=0;i<n;i++){
        board[idx] = i;
        if(isAble(idx))  // idx열에 넣을 수 있다면
            sol(idx+1);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    sol(0);
    cout << cnt;
    return 0;
}
