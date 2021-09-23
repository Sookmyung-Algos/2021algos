#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int visited[100001] = {0, };

void bfs(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == k) {
            cout << visited[k] << endl;
            break;
        }
        if (now + 1 <= 100000 && visited[now + 1] == 0) {
            visited[now + 1] = visited[now] + 1;
            q.push(now+1);
        }
        if (now - 1 >= 0 && visited[now - 1] == 0) {
            visited[now - 1] = visited[now] + 1;
            q.push(now-1);
        }
        if (now * 2 <= 100000 && visited[now * 2] == 0) {
            visited[now * 2] = visited[now] + 1;
            q.push(now*2);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    bfs(n);
    return 0;
}
