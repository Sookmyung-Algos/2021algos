#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int answer, H, hx, hy;
vector<pair<int, int>> milk;
vector<vector<int>> arr;

void dfs(int x, int y, int hp, int m) {
    for (pair<int, int> p: milk) {
        if (arr[p.first][p.second] == 2) {
            int d = abs(x - p.first) + abs(y - p.second);
            if (d <= hp) {
                arr[p.first][p.second] = 0;
                dfs(p.first, p.second, hp + H - d, m + 1);
                arr[p.first][p.second] = 2;
            }
        }
    }
    if (abs(x - hx) + abs(y - hy) <= hp)
        answer = max(answer, m);
}

int main(int argc, const char * argv[]) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    arr.reserve(10);
    
    int N, M;
    cin >> N >> M >> H;
    
    for (int i = 0; i < N; i++) {
        arr[i].reserve(10);
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
            
            if (tmp == 1) {
                hx = i; hy = j;
            } else if (tmp == 2) {
                milk.push_back(make_pair(i, j));
            }
        }
    }
    
    dfs(hx, hy, M, 0);
    cout << answer << '\n';
    
    return 0;
}
