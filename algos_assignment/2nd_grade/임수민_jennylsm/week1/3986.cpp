#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int A;    //검사할 단어의 수를 입력한다.
    cin >> A;
    int sum = 0;  //좋은 단어의 개수를 저장할 변수를 선언한다.
    while (A--) {
        stack<char> stack;
        string B;
        cin >> B;  //좋은 단어를 문자열로 입력받는다.
        for (int p = 0; p < B.length(); p++) {  //문자열의 길이동안 반복한다.
            if (stack.empty()) {
                stack.push(B[p]);   //스택이 비어있으면 push한다.
            }
            else {
                if (stack.top() == B[p]) {
                    stack.pop();     //스택의 top이 B[p]와 같다면 pop한다.
                }
                else {
                    stack.push(B[p]);   //그렇지 않은 경우 push한다.
                }
            }
        }
        if (stack.empty()) {
            sum++;  //for문 이후에 스택이 비어있으면 좋은 단어이다.
        }
    }
    cout << sum;
}
