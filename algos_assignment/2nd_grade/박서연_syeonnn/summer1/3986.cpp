#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    int cnt = 0;
    cin >> n;

    for (int j = 0; j < n; j++) {
        string word;
        stack<char> s;

        cin >> word;

        for (int i = 0;i<word.length(); i++) {
            if (s.empty()) {
                s.push(word[i]);
            }
            else {
                if (s.top() == word[i]) {
                    s.pop();
                }
                else {
                    s.push(word[i]);
                }
            }
        }
        if (s.empty()) {
            cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}
