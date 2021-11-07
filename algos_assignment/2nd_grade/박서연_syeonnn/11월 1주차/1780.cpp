//1780(실버2) 종이의 개수

#include <iostream>
using namespace std;

int N;
int paper[2188][2188];
int cnt[3]; // cnt[0] : -1로만 채워진 종이의 개수, cnt[1] : 0으로만 채워진 종이의 개수, cnt[2] : 1로만 채워진 종이의 개수

bool same(int x, int y, int n){
    for (int i = x; i < x + n; i++){
        for (int j = y; j < y + n; j++){
            if (paper[x][y] != paper[i][j])
                return false;
        }
    }
    return true;
}

void solve(int x, int y, int n){
    // 같은 숫자로 이루어진 종이면
    if (same(x, y, n))    {
        cnt[paper[x][y] + 1] += 1;
        return;
    }

    int m = n / 3;

    for (int i = 0; i < 3; i++)    {
        for (int j = 0; j < 3; j++)        {
            solve(x+i*m, y+j*m, m);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    for (int i = 0; i < 3; i++) cout << cnt[i] << "\n";

    return 0;
}
