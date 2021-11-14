#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int n, m;
int max_cnt = 0;
int map[8][8];
int virus_map[8][8];
vector<pair<int, int>> virus;

void bfs() {
    int cnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < virus.size(); i++) {
        q.push(make_pair(virus[i].first, virus[i].second));
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (virus_map[nx][ny] == 0) {
                virus_map[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (virus_map[i][j] == 0) cnt++;
        }
    }
    max_cnt = max(max_cnt, cnt);
    return;
}

void make_wall(int cnt) {
    if (cnt == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                virus_map[i][j] = map[i][j];
            }
        }
        bfs();
        return;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) {
                    map[i][j] = 1;
                    make_wall(cnt + 1);
                    map[i][j] = 0;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                make_wall(1);
                map[i][j] = 0;
            }
        }
    }
    cout << max_cnt;
    return 0;
}
