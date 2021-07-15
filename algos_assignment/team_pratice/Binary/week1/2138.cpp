#include <iostream>
#include <string>
using namespace std;
//그리디 알고리즘: 첫 번째 전구 스위치를 누르는 경우, 안누르는 경우로 나눠서 풀기

int n, result; //n: 전구의 개수, result: 최종 결과(횟수)
string now, now2, want; //now: 현재 상태, want: 원하는 결과

void push(int index) { //스위치 누르기
    for (int i = index - 1; i <= index + 1; i++) {
        if (i < 0 || i >= n) continue;
        if (now[i] == '0')    now[i] = '1';
        else now[i] = '0';
    }
}
int play(bool bulb) { //전구의 현재 상태 blub
    int cnt = 0;
    now = now2; //초기화

    if (bulb) { //첫 번째 전구 스위치를 누르는 경우
        push(0);
        cnt++;
    }

    for (int i = 1; i < n; i++) {//첫 번째 전구 스위치를 안누르는 경우
        if (now[i - 1] != want[i - 1]) {
            push(i);
            cnt++;
        }
    }

    if (now != want)    cnt = 100001; //불가능한 경우
    return cnt;
}
int main() {
    cin >> n >> now >> want;
    now2 = now;

    result = min(play(true), play(false));
    if (result == 100001)    cout << "-1";
    else cout << result;
    return 0;
}
