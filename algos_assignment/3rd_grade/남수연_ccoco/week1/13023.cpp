#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[2001];
vector<int> tree[2001];

void dfs(int x, int frnd) {
    if (frnd == 5) {
        cout << "1";
        exit(0);
    }
    visit[x] = true;
    for (int i = 0; i < tree[x].size(); i++) {
        int next = tree[x][i];
        if (!visit[next]) {
            dfs(next, frnd + 1);
        }
    }
    visit[x] = false;
}

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t, s;
        cin >> t >> s;
        tree[t].push_back(s);
        tree[s].push_back(t);
    }
    for (int i = 0; i < n; i++) {
        dfs(i, 1);
    }
    cout << "0";
    return 0;
}
