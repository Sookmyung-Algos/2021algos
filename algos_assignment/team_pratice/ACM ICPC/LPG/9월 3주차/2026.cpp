#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int k, n, m;
bool visit[1000][1000] = { false }, flag = false;
vector<int> v;

void dfs(int now, int psum) {
    if (psum == k) {
        flag = true;
        return;
    }
    for (int i = now + 1; i <= n; i++) {
        if (!visit[now][i]) continue;
        bool chk = false;
        for (int j = 0; j < v.size(); j++) {
            if (!visit[i][v[j]]) chk = true;
        }
        if (chk) continue;
        v.push_back(i);
        dfs(i, psum + 1);
        if (flag) return;
        v.pop_back();
    }
}

int main() {
    cin >> k >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        visit[x][y] = true;
        visit[y][x] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (flag) break;
        v.push_back(i);
        dfs(i, 1);
        v.pop_back();
    }
    if (!flag) cout << -1 << '\n';
    else {
        for (int i = 0; i < k; i++) cout << v[i] << '\n';
    }
}