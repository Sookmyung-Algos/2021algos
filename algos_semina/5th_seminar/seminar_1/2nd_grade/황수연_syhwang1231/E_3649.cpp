#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x, n;  // x: 구멍의 너비, n: 레고 조각 수
vector<int> lego;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> x) {  // 입력이 있을 동안만
        cin >> n;
        x *= 10000000;  // x는 cm단위이므로 nm로 고치기

        lego.clear();
        lego.resize(n);

        for (int i = 0; i < n; i++)
            cin >> lego[i];

        sort(lego.begin(), lego.end());  // 레고 길이 벡터 정렬

        int start = 0;  // 투 포인터 사용
        int end = n - 1;
        int sum = 0;

        while (1) {
            if (start >= end)  // 범위 벗어나면 break
                break;

            sum = lego[start] + lego[end];
            if (sum == x)  // 정답 찾은 경우
                break;
            else if (sum < x)
                start++;
            else
                end--;
        }

        if (sum != x)
            cout << "danger\n";
        else
            cout << "yes" << " " << lego[start] << " " << lego[end] << "\n";
    }
    return 0;
}
