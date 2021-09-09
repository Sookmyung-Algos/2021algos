#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
int visited[100001] = {0, };

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == k) {
            cout << visited[k] << endl;
            break;
        }
        if (now * 2 <= 100000 && (visited[now * 2] == -1 || visited[now * 2] > visited[now])) {
            visited[now * 2] = visited[now];
            q.push(now*2);
        }
        if (now + 1 <= 100000 && (visited[now + 1] == -1 || visited[now + 1] > visited[now] + 1)) {
            visited[now + 1] = visited[now] + 1;
            q.push(now+1);
        }
        if (now - 1 >= 0 && (visited[now - 1] == -1 || visited[now - 1] > visited[now] + 1)) {
            visited[now - 1] = visited[now] + 1;
            q.push(now-1);
        }
    }
}

int main(int argc, const char * argv[]) {
    memset(visited, -1, sizeof(int) * 100001);
    cin >> n >> k;
    bfs(n);
    return 0;
}
