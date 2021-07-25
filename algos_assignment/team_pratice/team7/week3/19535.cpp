#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool visit[300001] = {false, };
vector<int> tree[300001];
int d, g;

long long nc3(int n) {
    if (n >= 3)
        return n * (n - 1) * (n - 2) / 6;
    return 0;
}

void dfs(int x) {
    visit[x] = true;
    int size = tree[x].size();
    g += nc3(size);
    for (int i = 0; i < size; i++) {
        int next = tree[x][i];
        if (!visit[next]) {
            d += (size - 1) * (tree[next].size() - 1);
            dfs(next);
        }
    }
}

int main(int argc, const char * argv[]) {
    int e;
    cin >> e;
    for (int i = 0; i < e-1; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    dfs(1);
    if (d > g*3) cout << "D";
    else if (d < g*3) cout << "G";
    else cout << "DUDUDUNGA";
    
    return 0;
}
