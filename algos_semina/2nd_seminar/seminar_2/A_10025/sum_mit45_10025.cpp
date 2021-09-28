#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long ice[1000002];
long long d[1000002];
int main() {

    //양동이 개수, 좌우로 닿을 수 있는 거리, 얼음개수,양동이 좌표
    long long n, k, g, x;
    long long ans = 0;
    cin >> n >> k;

    // 얼음의 양과 좌표 입력
    // 배열 좌표에 얼음의 양 값 넣기
    for (int i = 0; i < n; i++) 
    {
        cin >> g >> x;
        ice[x] = g;
    }

    d[0] = ice[0];

    for (int i = 1; i <= 1000000; i++)
    {
        d[i] = d[i - 1] + ice[i];
    }

    if (k <= 1000000)
    {
        for (int i = 0; i <= 1000000; i++)
        {
            //현재위치 - k이전 빼기
            if (i + k <= 1000000 && i - k >= 1)
                ans = max(ans, d[i + k] - d[i - k - 1]);
        }
        cout << ans << '\n';
    }

    else
        cout << d[1000000] << '\n';
}
