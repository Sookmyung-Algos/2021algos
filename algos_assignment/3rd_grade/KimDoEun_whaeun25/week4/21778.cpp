#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int>> edge;
vector<vector<int>> visited;
vector<vector<int>> cnt;
vector<int> v, v2, v3;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m, answer = 0;

void bfs(int x, int y){
    
    visited[x][y] = 1;
    cnt[x][y]++;
    
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
            
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && edge[nx][ny] != 0) {
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                cnt[nx][ny] = cnt[xx][yy]+1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        edge.push_back(v);
        visited.push_back(v2);
        cnt.push_back(v3);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char a;
            
            cin >> a;
            
            edge[i].push_back(a-'0');
            visited[i].push_back(0);
            cnt[i].push_back(0);
        }
    }
    
    bfs(0, 0);
    
    cout << cnt[n-1][m-1];
}
