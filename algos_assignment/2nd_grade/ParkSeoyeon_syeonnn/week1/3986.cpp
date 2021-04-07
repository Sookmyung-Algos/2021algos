#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    while (n--) {
        stack<char> stack;
        string word;
        cin >> word;

        for (int i = 0; i < word.length(); i++) {
            if (stack.empty()) {
                stack.push(word[i]);//스택을 이용해 단어 중 이웃한 알파벳 두 개를 비교하기 위해 스택에 알파벳을 차례대로 push()한다.
            }
            else {
                if (stack.top() == word[i]){
                    stack.pop();//앞서 스택에 push()했던 word의 (i-1)번째 알파벳과 word의 i번째 알파벳이 같은 경우 스택을 pop()한다.
                }
                else {
                    stack.push(word[i]);//두 알파벳이 같지 않은 경우 그 다음 알파벳과 비교하기 위해 word[i]를 스택에 push()한다.
                }
            }
        }
    }

    if (stack.empty()) {
        count++;
    }//알파벳들이 모두 쌍을 이루어 pop()한 경우 스택이 비워진다. 즉, 좋은 단어이므로 count에 1을 더한다.


cout << count;
return 0;
}
