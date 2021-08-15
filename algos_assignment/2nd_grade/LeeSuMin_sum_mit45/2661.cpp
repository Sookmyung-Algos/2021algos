#include <iostream>
#include <string>
using namespace std;

int N;
string s;
bool flag;

void func(string t, int depth) {
    if (flag) return;

    int len = t.size();
    for (int i = 1; i <= (len / 2); i++) {
        if (t.substr(len - i, i) == t.substr(len - (2 * i), i)) {
            t = "";
            return;
        }
    }

    if (depth > N) return;

    if (depth == N) {
        flag = true;
        cout << t << "\n";
        return;
    }
    else {
        for (int i = 0; i < N; i++) {
            func(t + "1", depth + 1);
            func(t + "2", depth + 1);
            func(t + "3", depth + 1);
        }
    }
}

int main() {
    cin >> N;

    func(s, 0);

    return 0;
}
