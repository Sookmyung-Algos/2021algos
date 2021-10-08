#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
#define pll pair<ll, ll>
#define MAXDIS 2000000000

using namespace std;

long long n, ans, x, y;
pll arr[500001];
pll farthest[4];
int blocked[4];
int d[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        arr[i] = pll(a, b);
    }
    cin >> x >> y;

    for (int i = 0; i < 4; i++) {
        long long nx = x + d[i][0] * MAXDIS, ny = y + d[i][1] * MAXDIS;
        farthest[i] = pll(nx, ny);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            long long nx = arr[j].first, ny = arr[j].second;
            long long dist = abs(farthest[i].first - nx) + abs(farthest[i].second - ny);
            if (dist <= MAXDIS) {
                blocked[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < 4; i++)
        ans += blocked[i];

    printf("%s\n", ans == 4 ? "NO" : "YES");
}
