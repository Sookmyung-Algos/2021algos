#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector<int> cube;
int swch[10][10];
queue<vector<int>> q;
map<vector<int>, int> mp;

int n, m; // n: 큐브 개수 m: 스위치 개수
int ans = -1;

int check_end(vector<int> cur) {
    int start = cur[0];
    for (int i = 1; i < n; i++)
        if (start != cur[i]) return 0;
    return 1;
}

void bfs() {
    mp[cube] = 1;
    q.push(cube);

    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();

        if (check_end(cur)) {
            ans = mp[cur] - 1; return;
        }
        
        for (int i = 0; i < m; i++) { // 다음 스위치 선택
            vector<int> next;
            for (int j = 0; j < n; j++) // 해당 스위치 누르기
                next.push_back((cur[j] + swch[i][j]) % 5);
            if (mp.find(next) == mp.end()) {
                mp[next] = mp[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cube.push_back(x);
    }

    for (int i = 0, c; i < m; i++) {
        cin >> c;
        for (int j = 0, x; j < c; j++) {
            cin >> x;
            swch[i][x - 1] = i + 1;
        }
    }

    bfs();

    cout << ans << '\n';
    
    return 0;
}
