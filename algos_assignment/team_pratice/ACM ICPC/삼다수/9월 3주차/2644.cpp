#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
int n;
int a, b;
int map[MAX][MAX] = { 0, };
bool visited[MAX] = { 0, };
int depth[MAX] = { 0, };
queue<int> q;

void BFS(int v) {
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int w = 1; w <= n; w++) {
            if (map[v][w] == 1 && visited[w] == 0) {
                q.push(w);
                visited[w] = true;
                depth[w] = depth[v] + 1;
            }
        }
    }

}


int main() {
    cin >> n;
    cin >> a >> b;

    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }

    BFS(a);

    if (depth[b] == 0)
        cout << -1;
    else
        cout << depth[b];

}
