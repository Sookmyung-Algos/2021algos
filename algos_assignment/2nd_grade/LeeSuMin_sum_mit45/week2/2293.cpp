#include <iostream>

#define MAX 101
using namespace std;

// 변수 선언
int n, k; // n가지 종류, 합이 k원
int coin[MAX];
int value[10001];

void solution()
{
    value[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = coin[i]; j <= k; j++)
        {
            value[j] = value[j] + value[j - coin[i]];
        }
    }
    cout << value[k] << '\n';
}

int main(void)
{
    // 시간 초과
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> coin[i];

    solution();

    return 0;
}
