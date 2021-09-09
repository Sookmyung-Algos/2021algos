#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
int eff[10][4][4][4];
char ele[10][4][4][4];
bool visit[10];
struct state {
    int first;
    char second;
    state() { }
    state(int _eff, char _ele) : first(_eff), second(_ele) { }
};
vector<vector<state>> map(5, vector<state>(5));

void rotate(int t, int d);
int calculate_color(vector<vector<state>> v);
vector<vector<state>> putMaterial(vector<vector<state>> v, int row, int col, int type, int dir);
void dfs(vector<vector<state>> v, int cnt);

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int t = 0; t < n; t++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> eff[t][0][i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> ele[t][0][i][j];
            }
        }
        for (int d = 1; d <= 3; d++) {
            rotate(t, d);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = state(0, 'W');
        }
    }
    memset(visit, false, sizeof(visit));
    ans = -999999999;
    dfs(map, 0);
    cout << ans << "\n";
    return 0;
}
int calculate_color(vector<vector<state>> v) {
    int r, b, g, y;
    r = b = g = y = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            switch (v[i][j].second) {
            case 'R':
                r += v[i][j].first;
                break;
            case 'B':
                b += v[i][j].first;
                break;
            case 'G':
                g += v[i][j].first;
                break;
            case 'Y':
                y += v[i][j].first;
                break;
            default:
                break;
            }
        }
    }

    return 7 * r + 5 * b + 3 * g + 2 * y;
}
void rotate(int t, int d) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            eff[t][d][i][j] = eff[t][d - 1][3 - j][i];
            ele[t][d][i][j] = ele[t][d - 1][3 - j][i];
        }
    }
}
void dfs(vector<vector<state>> v, int cnt) {
    if (cnt == 3) {
        ans = max(ans, calculate_color(v));
        return;
    }
    for (int t = 0; t < n; t++) {
        if (!visit[t]) {
            visit[t] = true;
            for (int i = 0; i <= 1; i++) {
                for (int j = 0; j <= 1; j++) {
                    for (int d = 0; d < 4; d++) {
                        vector<vector<state>> tmp = putMaterial(v, i, j, t, d);
                        dfs(tmp, cnt + 1);
                    }
                }
            }
            visit[t] = false;
        }
    }
}
vector<vector<state>> putMaterial(vector<vector<state>> v, int row, int col, int t, int d) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            v[row + i][col + j].first += eff[t][d][i][j];
            if (v[row + i][col + j].first < 0)
                v[row + i][col + j].first = 0;
            else if (v[row + i][col + j].first > 9)
                v[row + i][col + j].first = 9;
            if (ele[t][d][i][j] != 'W') {
                v[row + i][col + j].second = ele[t][d][i][j];
            }
        }
    }
    return v;
}
