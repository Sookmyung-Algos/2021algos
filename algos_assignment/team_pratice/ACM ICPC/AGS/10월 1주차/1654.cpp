#include <iostream>
#include <algorithm>

using namespace std;

int k[10001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long K, N;
    cin >> K >> N;
    long long res(0);
    long long l = 1, r = 1;
    long long mid;

    for (int i = 0; i < K; i++) {
        cin >> k[i];

        if (r < k[i])
            r = k[i];
    }

    while (l <= r) {
        int sum(0);
        mid = (l + r) / 2;

        for (int i = 0; i < K; i++)
            sum += (k[i] / mid);

        if (sum < N)
            r = mid - 1;
        else {
            res = max(res, mid);
            l = mid + 1;
        }
    }
    cout << res << "\n";
    return 0;
}
