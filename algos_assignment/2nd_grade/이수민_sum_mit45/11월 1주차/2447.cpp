#include <iostream>
using namespace std;

void check(int i, int j, int num){
    if((i / num)%3 == 1 && (j / num)%3 == 1) {
        cout << ' ';
    }
    else{
        if(num / 3 == 0)
            cout <<'*';
        else
            check(i,j,num/3);
    }
}
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            check(i,j,N);
        cout << '\n';
    }
}
