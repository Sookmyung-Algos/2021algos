#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool vps(string ps) {
    stack<char> s;
    bool sw = true;
    
    for (int i = 0; i < ps.size(); ++i) {
        if (ps[i] == '(')
            s.push(ps[i]);
        else if (!s.empty() && ps[i] == ')')
            s.pop();
        else if (s.empty() && ps[i] == ')') {
            sw = false;
            break;
        }
    }
    if (s.empty() && sw) return true;
    else return false;
}

int main() {
    int num;
    string ps;
    cin >> num;
    
    for (int i = 0; i < num; ++i) {
        cin >> ps;
        if (vps(ps)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
