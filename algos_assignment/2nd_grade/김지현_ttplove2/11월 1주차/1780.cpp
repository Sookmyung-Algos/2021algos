#include <iostream>
using namespace std;

int N;
int paper[2200][2200];
int result[3] = { 0, };

void check(int x, int y, int num)
{
    int first = paper[x][y];// 비교를 시작할 첫번째 칸에 적힌 숫자를 저장
    bool same = true; 
    for (int i = x; i < x + num; i++){ // 전부 같은 숫자인지 확인
        for (int j = y; j < y + num; j++) {
            if (paper[i][j] != first) { // 현재 칸의 숫자와 first에 저장된 값이 다르면 
                same = false; // bool 타입의 same 변수에 false 저장
            }
        }
    }
    if (same) { // 전부 같은 경우
        result[first + 1]++;
    }
    else { // 아닌 경우 전체 크기를 3으로 나눠서 다시 확인한다
        int newN = N / 3;
        for (int a = x; a < x + num; a += num / 3) {
            for (int b = y; b < y + num; b += num / 3) {
                check(a, b, num / 3);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    check(0, 0, N);

    for (int i = 0; i < 3; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
