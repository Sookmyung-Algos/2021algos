// 9461 (실버3) 파도반 수열

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

long long p[101] = { 1,1,1, };

long long P(int x) {

    if (p[x] != 0) {
        return p[x];
    }   // 시간초과 오류 해결하기 위해 필요, 아니면 재귀 사용안하는 방법 필요

    else {
        p[x] = P(x - 2) + P(x - 3);
        return p[x];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t,T;    //테스트케이스 수, 각 케이스의 정수n

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> T;
        cout << P(T-1) << '\n';
    }

    return 0;
}
