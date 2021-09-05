// S1_5904 Moo게임.cpp
//moo(n-1) + mo....o + moo(n-1)
#include <iostream>
using namespace std;

int N;
int idx;

void moo(int x){

    if (x == 1){
        if (idx + 1 == N){
            cout << "m\n";
            exit(0);
        }

        else if (idx + 2 == N || idx + 3 == N){
            cout << "o\n";
            exit(0);
        }

        idx += 3;
        return;
    }

    moo(x - 1);
    if (idx + 1 == N){
        cout << "m\n";
        exit(0);
    }
    idx++;

    for (int i = 0; i <= x; i++){

        if (idx + 1 == N){
            cout << "o\n";
            exit(0);
        }
        idx++;
     }

    moo(x - 1);
}



int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    moo(30); // 일단 돌리고 중간에 출력

    return 0;
}
