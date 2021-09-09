// 1018 체스판 칠하기
#include <iostream>
#include <vector>
#define MAX 51

using namespace std;
int N, M;
int arr[MAX][MAX];

int BB[8][8] = { // 첫 번째 칸이 검은색
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1
};

int WB[8][8] = {// 첫 번째 칸이 흰색
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0
};
// 각각 완벽한 체스판을 배열로 저장하여 비교하는 방식. 

// 첫번째 칸이 검은색인 경우
int Bcnt(int a, int b)
{
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arr[i + a][j + b] != BB[i][j]) {
                // 저장한 체스판 배열과 비교하여 다르면 카운트
                cnt++;
            }
        }
    }
    return cnt;
}

// 첫번째 칸이 흰색인 경우
int Wcnt(int a, int b)
{
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arr[i + a][j + b] != WB[i][j]) {
                // 저장한 체스판 배열과 비교하여 다르면 카운트
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int minnum = 64;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == 'B') arr[i][j] = 1;
            else arr[i][j] = 0;
            // 검은색이면 1, 흰색이면 0을 저장한다.
        }    }

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++)
        {
            int result = min(Bcnt(i, j), Wcnt(i, j));
            minnum = min(result, minnum);
            // 첫 번째 칸이 흰색이어도 이를 검은색으로 칠하는 방법이 더 최선의 방법일 수도 있으니 
            // 두 경우를 전부 구하고 그 결과를 비교하여 작은 수를 저장한다.
        }
    }
    cout << minnum << "\n";
    return 0;
}
