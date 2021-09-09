#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
string s;
stack<char>st;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;

    bool flag = false;
    int val = 0;
    int tmp = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push('(');
            tmp *= 2;
        }
        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                flag = true;
                break;
            }
            if (s[i - 1] == '(') {
                val += tmp;
            }
            tmp /= 2;
            st.pop();
        }
        else if (s[i] == '[') {
            st.push('[');
            tmp *= 3;
        }
        else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                flag = true;
                break;
            }
            if (s[i - 1] == '[') {
                val += tmp;
            }
            tmp /= 3;
            st.pop();
        }
    }
    if (flag || !st.empty()) {
        cout << 0;
    }
    else cout << val;
}
