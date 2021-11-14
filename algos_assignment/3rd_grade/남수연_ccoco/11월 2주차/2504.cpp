#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


int main(int argc, const char * argv[]) {
    stack<int> s;
    int tmp;
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        switch (str[i]) {
            case '(':
                s.push(-1);
                break;
            case '[':
                s.push(-2);
                break;
            case ')':
                tmp = 0;
                while (1) {
                    if (s.empty()) {
                        printf("0");
                        return 0;
                    }
                    int t = s.top();
                    s.pop();
                    if (t > 0) tmp += t;
                    if (t == -1) {
                        if (tmp == 0) tmp = 1;
                        s.push(tmp * 2);
                        break;
                    }
                    if (t == -2) {
                        printf("0");
                        return 0;
                    }
                }
                break;
            case ']':
                tmp = 0;
                while (1) {
                    if (s.empty()) {
                        printf("0");
                        return 0;
                    }
                    int t = s.top();
                    s.pop();
                    if (t > 0) tmp += t;
                    if (t == -2) {
                        if (tmp == 0) tmp = 1;
                        s.push(tmp * 3);
                        break;
                    }
                    if (t == -1) {
                        printf("0");
                        return 0;
                    }
                }
                break;
            default:
                break;
        }
    }
    int sum = 0;
    while (!s.empty()) {
        if (s.top() < 0) {
            printf("0");
            return 0;
        }
        sum += s.top();
        s.pop();
    }
    printf("%d", sum);
    return 0;
}
