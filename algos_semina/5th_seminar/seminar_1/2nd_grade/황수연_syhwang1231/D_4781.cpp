#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, c;
double m, p;
int dp[10001];  // dp[n]: n원으로 얻을 수 있는 최대 칼로리

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (1) {
        cin >> n >> m;
        if (n == 0)  // ?
            break;
        memset(dp, 0, sizeof(dp));

        int intM = m * 100 + 0.5;

        for (int i = 0; i < n; i++) {   // 칼로리, 가격 입력
            cin >> c >> p;
            int intP = p * 100 + 0.5;  // 소수점 둘째자리까지 있는 실수를 정수로
            for (int j = intP; j <= intM; j++) {
                dp[j] = max(dp[j], dp[j - intP] + c);
            }
        }

        cout << dp[intM] << "\n";  // 갖고 있는 돈 m원으로 얻을 수 있는 최대 칼로리
    }
    return 0;
}
