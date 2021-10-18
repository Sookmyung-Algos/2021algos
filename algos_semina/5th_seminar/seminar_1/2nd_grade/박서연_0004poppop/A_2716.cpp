// 2716 (실버2) 원숭이 매달기

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    char c;
    string s;

    cin >> n;
    c = cin.get();  // 의미없는 값 처리

    while(n--) {    // 테스트 케이스들에 대해
        getline(cin, s);    // 문자열 입력받기

        int level = 0, maxlevel = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '[') {  // 열린 괄호일때
                level++;    // 덩굴이 한 번 더 나뉘어졌다고 가정, 층위 증가
                if (level > maxlevel) maxlevel = level; // 최대값 저장
            }
            else level--;   // 층위 감소
        }

        long long result = 1;
        for (int j = 0; j < maxlevel; j++)
            result *= 2;

        cout << result << '\n';
    }

    return 0;
}
