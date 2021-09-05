#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int visit[20001];
vector<int> tree[20001];
string answer = "YES";
int v, e;

void dfs(int x, int check) {
    visit[x] = check;
    for (int i = 0; i < tree[x].size(); i++) {
        int next = tree[x][i];
        if (visit[next] == -1) {
            dfs(next, (check + 1) % 2);
        } else if (visit[next] == check) {
            answer = "NO";
            return;
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v >> e;
        answer = "YES";
        memset(visit, -1, sizeof(visit));
        for (int k = 1; k <= v; k++) {
            tree[k].clear();
        }
        for (int j = 0; j < e; j++) {
            int from, to;
            cin >> from >> to;
            tree[from].push_back(to);
            tree[to].push_back(from);
        }
        for (int l = 1; l <= v; l++) {
            if (visit[l] == -1) {
                dfs(l, 0);
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
