#include <iostream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;
char map[3001][3001];
int n, m,ans,  R, C;
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };
vector<vector<int>>d(3001, vector<int>(3001, -1));

int bfs() {
    d[R][C] = 0;
    queue <pair <int, int>> q;
    q.push({ R, C });
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (map[r][c] > '2') 
            return d[r][c];

        for (int i = 0; i < 4; i++) {
            int nextR = r + dr[i];
            int nextC = c + dc[i];
            if (0 > nextR || nextR >= n || 0 > nextC || nextC >= m)
                continue;
            if (map[nextR][nextC] == '1' || d[nextR][nextC] >= 0)
                continue;

            d[nextR][nextC] = d[r][c] + 1;
            q.push({ nextR, nextC });
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == '2') {
                R = i;
                C = j;
            }
        }
    }
    ans = bfs();
    if (ans == -1) cout << "NIE";
    else cout << "TAK\n" << ans;
}
