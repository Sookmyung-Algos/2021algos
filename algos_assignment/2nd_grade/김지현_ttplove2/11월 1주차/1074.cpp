#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int result = 0;

void solve(int y, int x, int n)
{
    if (y == r && x == c) {
        cout << result;
        return;
    }
    if (y <= r && r < (y + n) && x <= c && c < (x + n)) {
        int newN = n / 2;
        solve(y, x, newN);
        solve(y, x + newN, newN);
        solve(y + newN, x, newN);
        solve(y + newN, x + newN, newN);
    }
    else result += (int)pow(n, 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> r >> c;
    solve(0, 0, (int)pow(2, N));

    return 0;
}
