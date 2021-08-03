#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<pair<int, int>> mc; // 민초 좌표
int visit[11];

int n, m, h, ans = 0;
int hx, hy; // 집 위치

void func(int x, int y, int r, int cnt) {
    if (cnt > ans && abs(x - hx) + abs(y - hy) <= r) ans = cnt;

    if (r <= 0 || cnt == mc.size()) return;

    for (int i = 0; i < mc.size(); i++) {
        if (!visit[i]) {
            int dist = abs(x - mc[i].first) + abs(y - mc[i].second);
            if (r >= dist) {
                visit[i] = 1;
                func(mc[i].first, mc[i].second, r + h - dist, cnt + 1);
                visit[i] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> h;

    int x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x == 2) mc.push_back({ i, j });
            else if (x == 1) hx = i, hy = j;
        }
    }

    func(hx, hy, m, 0);

    cout << ans << '\n';

    return 0;
}
