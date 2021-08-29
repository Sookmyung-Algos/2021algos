// 1915 가장 큰 정사각형 (Gold 5)
#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

int n, m;
int arr[MAX][MAX];
int ans = 0;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    string s;  // 띄어쓰기 없이 입력되기 때문에 string으로 받아서 한 문자씩 저장

    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++)
            arr[i][j] = s[j-1] - '0';
    }

    if (n == 1 || m == 1) {  // 가로 혹은 세로의 길이가 1인 경우는 따로 처리
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == 1) {
                    ans = 1;
                    break;
                }
            }
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] != 0) {  // 정사각형의 오른쪽 아래 꼭짓점을 보았을때 왼쪽 위로 정사각형 만들 수 있는지, 변의 길이 저장
                    arr[i][j] = min(arr[i - 1][j - 1], min(arr[i][j - 1], arr[i - 1][j])) + 1;
                    ans = max(ans, arr[i][j]);
                }
            }
        }
    }
    cout << ans * ans;
    return 0;
}
