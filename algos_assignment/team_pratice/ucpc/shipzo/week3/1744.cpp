#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> pq1; // 내림차순 (양수 저장)
priority_queue<int, vector<int>, greater<int>> pq2; // 오름차순 (0, 음수 저장)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x, tmp, sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0) pq1.push(x);
        else pq2.push(x);
    }

    while (pq1.size() > 0) {
        if (pq1.top() == 1) {
            sum += pq1.top();
            pq1.pop();
            continue;
        }

        if (pq1.size() == 1) {
            sum += pq1.top();
            pq1.pop();
        }

        else {
            tmp = pq1.top(); pq1.pop();
            if (pq1.top() == 1) {
                sum += tmp;
                continue;
            }
            tmp *= pq1.top(); pq1.pop();
            sum += tmp;
        }
    }

    while (pq2.size() > 0) {
        if (pq2.size() == 1) {
            sum += pq2.top();
            pq2.pop();
        }
        else {
            tmp = pq2.top(); pq2.pop();
            tmp *= pq2.top(); pq2.pop();
            sum += tmp;
        }
    }

    cout << sum << '\n';

    return 0;
}
