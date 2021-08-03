#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<pair<int, int>> d;
int cal[1003][370];

bool f(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    else return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, a, b, st = 367, en = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        d.push_back({ a, b });
        st = min(st, a);
        en = max(en, b);
    }

    sort(d.begin(), d.end(), f);

    int cnt = 0, max_num = 0;
    while (!d.empty()) {
        pair<int, int> cur = d.front();
        d.pop_front();
        for (int i = 0; i < 1001; i++) {
            if (!cal[i][cur.first]) {
                for (int j = cur.first; j <= cur.second; j++) cal[i][j] = 1;
                max_num = max(max_num, i);
                break;
            }
        }
    }

    int mark = 0, w_st = 366, w_en = 0, h = 0, sum = 0;
    for (int i = st; i <= en + 1; i++) {
        mark = 0;
        for (int j = 0; j <= max_num; j++) {
            if (cal[j][i] == 1) {
                w_st = min(w_st, i);
                w_en = max(w_en, i);
                h = max(h, j + 1);
                mark = 1;
            }
        }
        if (!mark) {
            sum += (w_en - w_st + 1) * h;
            w_st = 366;
            w_en = 0;
            h = 0;
        }
    }

    cout << sum << '\n';

    return 0;
}
