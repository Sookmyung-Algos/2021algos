#include <iostream>
using namespace std;
long long arr[1000001],g, n, k, s, ans = 0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0, b, c; i < n; i++) {
        cin >> b >> c;
        arr[c] = b;
    }
    k = k * 2 + 1;
    for (int i = 0; i <= 1000000; i++) {
        if (i >= k) {
            s -= arr[i - k];
        }
        s += arr[i];
        ans = s > ans ? s : ans;
    }
    cout << ans << endl;
    return 0;
}
