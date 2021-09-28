#include <iostream>
#include <vector>
#define MAX 1000000000
using namespace std;

long long N;
int K;
vector<long long int> MooLen;

void getLen(long long prev, int k) {  // S(k) 길이 구하기
    long long cur = prev * 2 + k + 3;
    if (cur > 1e9) {
        MooLen.push_back(cur);
        return;
    }
    MooLen.push_back(cur);
    getLen(cur, k + 1);
    return;
}

char MooArr(long long n) {
    if (n <= 3) {
        if (n == 1)
            return 'm';
        else
            return 'o';
    }

    int idx = 1;  // 현재 N이 속한 moo 수열의 k를 다시 구하기
    while (n > MooLen[idx]) {
        idx++;
    }

    if (n <= MooLen[idx] - MooLen[idx - 1]) {  // 중간에 mo..o 에 있는 경우
        if (n == MooLen[idx - 1] + 1)
            return 'm';
        else
            return 'o';
    }

    else  // S(n-1)에 있는 경우, S(n-1)에 대해 재귀 호출
        return MooArr(n - MooLen[idx - 1] - (idx + 3));  // n값을 S(n-1)범위에 맞게 갱신

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    MooLen.push_back(3);  // 첫번째 수열은 길이가 3
    getLen(3, 1);

    cout << MooArr(N);
    return 0;
}
