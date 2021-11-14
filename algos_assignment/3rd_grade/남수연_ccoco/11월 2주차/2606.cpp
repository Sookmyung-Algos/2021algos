#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

bool visit[101] = {false, };
vector<int> tree[101];
int total;

void dfs(int x) {
    total++;
    visit[x] = true;
    for (int i = 0; i < tree[x].size(); i++) {
        int next = tree[x][i];
        if (!visit[next]) {
            dfs(next);
        }
    }
}

int main(int argc, const char * argv[]) {
    int v, e;
    
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    
    dfs(1);
    cout << total - 1;
    return 0;
}
