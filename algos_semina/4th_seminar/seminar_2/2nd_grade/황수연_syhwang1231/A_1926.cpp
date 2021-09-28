#include <iostream>
#include <vector>
#define MAX 501
using namespace std;

int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
bool visited[MAX][MAX];
vector<int> painting[MAX];
vector<int> each;
int area;
int n, m;

void dfs(int r, int c) {
    area++;

    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 <= nr && nr < n && 0 <= nc && nc < m) {
            if (!visited[nr][nc] && painting[nr][nc] == 1)
                dfs(nr, nc);
        }
    }
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            painting[i].push_back(tmp);
        }
    }
    int cnt = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (painting[i][j] == 1 && !visited[i][j]) {
                area = 0;
                dfs(i, j);  // 1번 dfs 하면 그림 1개 찾음
                cnt++;
                answer = max(answer, area);
            }
        }
    }

    cout << cnt << "\n" << answer;
    return 0;
}
