#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> left;
    stack<char> right;   //L과 D를 수행할 스택 선언
    string s;
    cin >> s;   //첫째줄에 받을 문자열 입력

    for (int i = 0; s[i] != '\0'; i++) {
        left.push(s[i]);
    }

    int p;
    cin >> p;   // 입력할 명령어 개수 입력

    while (p--) {
        char a;    //반복문을 통해 수행할 명령 입력
        cin >> a;

        if (a == 'L' && !left.empty()) {  //L이 입력된 경우 left에 저장
            right.push(left.top());
            left.pop();
        }
        else if (a == 'D' && !right.empty()) {    //D가 입력된 경우 right에 저장
            left.push(right.top());
            right.pop();
        }
        else if (a == 'B' && !left.empty()) {  //B가 입력된 경우 left에서 삭제
            left.pop();
        }
        else if (a == 'P') {  //P가 입력된 경우 left에 문자 추가
            char c;
            cin >> c;
            left.push(c);
        }
    }

    stack<char> print;     //출력
    while (!left.empty()) {
        print.push(left.top());
        left.pop();
    }

    while (!print.empty()) {
        cout << print.top();
        print.pop();
    }
    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }
    return 0;
}
