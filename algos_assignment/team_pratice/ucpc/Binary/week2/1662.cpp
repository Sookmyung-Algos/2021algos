#include <iostream>
using namespace std;

bool visited[50];
int calc(string& s, int idx);

int main(void) {
    string s;
    cin >> s;
    cout << calc(s, 0);
    return 0;
}
int calc(string& s, int index) {
    int cnt = 0;
    for (int i = index; i < (int)s.length(); i++) {
        if (!visited[i]) {
            if (s[i] == '(') {
                visited[i] = true;
                cnt += (s[i - 1] - '0') * calc(s, i) - 1;
            }
            else if (s[i] == ')') {
                visited[i] = true;
                return cnt;
            }
            else {
                cnt++;
                visited[i] = true;
            }
        }
    }
    return cnt;
}
