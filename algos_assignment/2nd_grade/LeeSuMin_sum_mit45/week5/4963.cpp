#include <iostream>
#include <vector>

using namespace std;
int map[51][51];
int vis[51][51];
int w = 1, h = 1;

int dx[] = { -1, 1, -1, 1, 0, 0, -1, 1 };
int dy[] = { -1, 1, 1, -1, 1, -1, 0, 0 };

// dfs 구현
void dfs(int x, int y)
{
    vis[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= h || ny >= w)
            continue;
        if (!vis[nx][ny] && map[nx][ny])
            dfs(nx, ny);
    }
}


int main()
{

    while (true) {
        int cnt = 0;
        cin >> w >> h;
        if (!w && !h)
            break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                vis[i][j] = false;
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!vis[i][j] && map[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
