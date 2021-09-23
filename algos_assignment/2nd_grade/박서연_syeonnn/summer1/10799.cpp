#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char>s;
    string br;  // 괄호가 나열됨
    int ans=0;    // 잘려진 쇠막대기 조각의 총 개수

    cin >> br;

    for (int i = 0; i < br.length(); i++) { // 쇠막대기의 시작
        if (br[i] == '(') {
            s.push(br[i]);
        }
        else if (br[i] == ')' && br[i - 1] == '(') {    // 레이저
            s.pop();
            ans += s.size();
        }
        else {    // 쇠막대기의 끝
            ans++;
            s.pop();
        }
    }
    cout << ans << '\n';

    return 0;
}
