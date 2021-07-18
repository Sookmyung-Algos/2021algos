//참고 : https://jaimemin.tistory.com/895
//에라토스테네스 체 사용 but 계속 MAX까지의 소수 찾기에서 시간오류 발생.

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000000;

int minFactor[MAX];
vector<int> prime; //소수

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    minFactor[0] = minFactor[1] = -1;
    for (int i = 2; i < MAX; i++)
        minFactor[i] = i; //minFactor=[-1, -1, 2, 3, ...]

    for (int i = 2; i * i < MAX; i++) //i*i 수와 수를 나누면 몫과 나누는 수 하나는 무조건 sqrt 이하가 됨.
        if (minFactor[i] == i)
            for (int j = i * i; j < MAX; j += i) //4, 6, 8... 9, 18, ...
                if (minFactor[j] == j)
                    minFactor[j] = i;

    for (int i = 3; i < MAX; i++)
        if (minFactor[i] == i)
            prime.push_back(i);

    while (1)
    {
        int N;
        cin >> N;

        if (N == 0) break;

        for (int i = 0; i < prime.size(); i++)
            if (minFactor[N - prime[i]] == N - prime[i])
            {
                cout << N << " = " << prime[i] << " + " << N - prime[i] << "\n";
                break;
            }
    }
    return 0;
}
