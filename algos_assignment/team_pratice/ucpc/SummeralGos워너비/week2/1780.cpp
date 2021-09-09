// 1780 종이의 개수
#include <iostream>
using namespace std;

int N;
int map[2188][2188];
int result[3] = { 0, };

void check(int x, int y, int num)
{
    int start = map[x][y];
    bool paper = true;
    // 전부 같은 숫자인지 확인
    for (int i = x; i < x + num; i++){
        // 0부터가 아니라, 매개변수로 받은 좌표를 시작점으로 정함
        for (int j = y; j < y + num; j++) {
            if (map[i][j] != start) {
                paper = false;
                // 다른 경우에는 false를 저장
            }
        }
    }
    if (paper) { // 전부 같은 숫자면 해당 숫자의 결과에 1을 더함
        result[start + 1]++;
    }
    else { // 다른 경우
        int newN = num / 3;
        // 3으로 나눈 값을 새로운 길이로 저장함
        for (int a = x; a < x + num; a += num / 3) {
            for (int b = y; b < y + num; b += num / 3) {
                check(a, b, num / 3);
                // 재귀함수 방식 사용
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
            // 이중반복문으로 내용 입력받음
            cin >> map[i][j];
        }
    }

    check(0, 0, N);

    for (int i = 0; i < 3; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
