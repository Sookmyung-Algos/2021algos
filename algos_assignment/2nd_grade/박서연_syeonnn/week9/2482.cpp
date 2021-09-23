// 2482 색상환

#include<iostream>
#include<algorithm>

using namespace std;

int N, K;   // 색상환에 포함된 색의 개수, 색상환에서 선택할 색의 개수
int dp[1004][1004]; // N색상환에서 인접한 두 색을 선택하지 않고 K개 색을 고를 수 있는 경우의 수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i <= N; i++) 
    {
        dp[i][1] = i;   // i개 색상환에서 1개 색을 고를 경우의 수는 i개
    }

    for (int m = 4; m <= N; m++) 
    {
        for (int n = 2; n <= K; n++) 
        {
            dp[m][n] = dp[m - 2][n - 1] + dp[m - 1][n];
            /*
            이는 색상환을 선형구조로 여기고 계산하는 방법인데 
            재귀적으로 dp값이 계산되므로 1번째와 n번째 배열이 동시에 선택되는 경우는 자동으로 탈락한다.
            따라서, dp[m-3][n-1]이 아님에 주의한다. 
            */
            dp[m][n] %= 1000000003;
            // 오버플로우를 피하기 위해 계산 과정에서 주어진 값으로 나누기를 반복함            
        }
    }

    cout << dp[N][K] << '\n';

    return 0;
}
