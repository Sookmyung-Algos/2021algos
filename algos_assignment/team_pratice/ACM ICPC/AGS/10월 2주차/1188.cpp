#include <iostream>

using namespace std;

inline int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int n, m, res;
    cin >> n >> m;

    int re = n % m;

    if (!re) {
        cout << 0;
        return 0;
    }

    int regroup = gcd(re, m);
    int transfer = m / regroup;
    res += regroup * (transfer - 1);

    cout << res;
}
