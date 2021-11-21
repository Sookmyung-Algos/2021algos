#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

const int MAX = 101;

int n, m;
int net[MAX][MAX];
bool visited[MAX];
int cnt[MAX];
int tmp = MAX;
queue<int> q;

void visit(int num) {
    q.push(num);
    visited[num] = true;
}

bool BFS(int num) {
    visit(num);
    while (!q.empty()) {
        int user = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && net[user][i]) {
                cnt[i] = cnt[user] + 1;
                visit(i);
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += cnt[i];
    if (sum < tmp) {
        tmp = sum;
        return true;
    }
    else return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        net[a][b] = 1;
        net[b][a] = 1;
    }

    int res;
    for (int i = 1; i <= n; i++) {
        if (BFS(i)) res = i;
        memset(visited, false, sizeof(visited));
        memset(cnt, 0, sizeof(cnt));
    }

    cout << res;

    return 0;
}
