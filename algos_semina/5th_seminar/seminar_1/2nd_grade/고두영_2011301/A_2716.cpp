#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

int k[10001];

int main() {
    int n;
    string s;
    char c;

    cin >> n;
    c = cin.get();

    while (n--) {
        stack<int> stack;
        int depth = 0;

        unsigned long long res = 1;
        getline(cin, s);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                stack.push(0);
                depth = max(depth, (int)stack.size());
            }
            else
                stack.pop();
        }
        for (int i = 0; i < depth; i++)
            res = res * 2;

        cout << res << '\n';
    }
}
