#include <iostream>
using namespace std;

int n, k; // 동전의 종류의 개수 n, 동전의 가치 k
int coin[101]; // 동전의 종류
int value[10010]; // 동전의 가치

int main(void)
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> coin[i]; // 동전의 종류 입력

    value[0] = 1; //x원짜리를 이용해서 x원을 만드는 경우는 1가지, value[x]+=value[0]에서 value[0]==1이어야 성립
    for (int i = 1; i <= n; i++)
    {
        for (int j = coin[i]; j <= k; j++)  value[j] += value[j - coin[i]];
        //그 동전이 가진 가치만큼을 뺀 나머지 액수를 만드는 경우의 수가 더해짐
    }
    cout << value[k];

    return 0;
}
