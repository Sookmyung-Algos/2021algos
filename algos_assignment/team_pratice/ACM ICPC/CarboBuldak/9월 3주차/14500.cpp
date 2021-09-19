#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    int arr[510][510] = {0};
    int answer = 0;
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i+2][j+2];
        }
    }
    for (int i = 2; i < N + 2; i++) {
        for (int j = 2; j < M + 2; j++) {
            // 세로로 길게 3개
            int di[] = {-1, 0, 1, 2, 3, 2, 1, 0};
            int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};
            int tmp = arr[i][j] + arr[i+1][j] + arr[i+2][j];
            for (int k = 0; k < 8; k++) {
                int tmp2 = tmp + arr[i + di[k]][j + dj[k]];
                answer = max(tmp2, answer);
            }
            // 가로로 길게 3개
            int tmp_2 = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            for (int k = 0; k < 8; k++) {
                int tmp2_2 = tmp_2 + arr[i + dj[k]][j + di[k]];
                answer = max(tmp2_2, answer);
            }
            // 정사각형
            int tmp_3 = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
            answer = max(tmp_3, answer);
            // 계단 1
            int tmp_4 = arr[i][j] + arr[i][j+1] + arr[i-1][j+1] + arr[i-1][j+2];
            answer = max(tmp_4, answer);
            // 계단 2
            int tmp_5 = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2];
            answer = max(tmp_5, answer);
            // 계단 3
            int tmp_6 = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1];
            answer = max(tmp_6, answer);
            // 계단 4
            int tmp_7 = arr[i][j] + arr[i+1][j] + arr[i+1][j-1] + arr[i+2][j-1];
            answer = max(tmp_7, answer);
        }
    }
    
    cout << answer;
    return 0;
}
