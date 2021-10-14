#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp(int x) {
    if (!x) return 1;
    ll tmp = dp(x / 2);
    return (tmp * tmp * (x % 2 + 1)) % 1000000007;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, T;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n == 1) cout << 1 << '\n';
        else cout << dp(n - 2) << '\n';
    }
}
