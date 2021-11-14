// icpc B번

#include <iostream>
#include <vector>
using namespace std;

int n;
int me;
int home;
vector <pair<int, int>> v;

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, c;
        char b;
        cin >> a >> b >> c;

        int start = a;
        int end;
        if (b == 'L') {
            end = a - c;
        }
        else if (b == 'R') {
            end = a + c;
        }
        v.push_back(make_pair(start, end));
    }

    cin >> me; // 현재 내위치 0

    int move = 1;
    while (move <= n) {
        for (int i = 0; i < n; i++) {
            if (me == v[i].first) {
                me = v[i].second;
                break;
            }
        }
        if (move == n)cout << me;
        move++;
    }

    return 0;
}
