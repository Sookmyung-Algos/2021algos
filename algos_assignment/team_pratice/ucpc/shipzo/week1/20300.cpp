#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, loss;
    deque <long long> t;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> loss;
        t.push_back(loss);
    }

    if (n % 2 != 0) {
        t.push_front(0);
    }
    sort(t.begin(), t.end());

    long long tmp, M = 0;

    while (!t.empty()) {
        tmp = t.front() + t.back();
        t.pop_front(); t.pop_back();

        if (tmp > M) {
            M = tmp;
        }
    }

    cout << M;

    return 0;
}
