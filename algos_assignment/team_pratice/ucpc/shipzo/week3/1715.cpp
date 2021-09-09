#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long n, x, tmp, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }

    while (pq.size() != 1) {
        tmp = pq.top(); pq.pop();
        tmp += pq.top(); pq.pop();
        pq.push(tmp);
        sum += tmp;
    }

    cout << sum << '\n';

    return 0;
}
